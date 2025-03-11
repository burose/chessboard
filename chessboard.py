import sensor, lcd, time
import image
from machine import UART #串口库函数
from fpioa_manager import fm # GPIO重定向函数

# 摄像头初始化
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.set_vflip(0)  # 摄像头后置模式

# 把True改成False就可以关闭水平镜像
sensor.set_hmirror(False)

# LCD初始化
lcd.init()

clock = time.clock()

#初始化串口引脚
fm.register(7, fm.fpioa.UART1_TX, force=True)
uart_A = UART(UART.UART1, 115200, 8, 0, 1, timeout=1000, read_buf_len=4096)
chessboard=[]

#数据发送函数
def sending_data(img_00,img_01,img_02,img_10,img_11,img_12,img_20,img_21,img_22):
    FH = bytearray([0x2C,0x12,img_00,img_01,img_02,img_10,img_11,img_12,img_20,img_21,img_22,0x5B])
    uart_A.write(FH);
# 获取中心区域的坐标和尺寸
def get_center_grid_coords():
    screen_width = lcd.width()
    screen_height = lcd.height()
    step = 200  # 设定为200x200的区域
    x = (screen_width - step) // 2
    y = (screen_height - step) // 2
    return (x+33, y+7, step-40, step-40)

# 获取9个小方格区域的坐标和尺寸
def get_subgrid_coords(x, y, w, h):
    subgrid_size = w // 3  # 每个小方格的尺寸
    subgrid_coords = []
    for j in range(3):
        for i in range(3):
            sub_x = x + i * subgrid_size
            sub_y = y + j * subgrid_size
            subgrid_coords.append((sub_x, sub_y, subgrid_size, subgrid_size))
    return subgrid_coords

# 计算灰度值
def get_gray_value(image, x, y):
    return image.get_pixel(x, y)  # 获取灰度值

# 计算每个小方格中心的颜色
def classify_subgrids(img, subgrid_coords):
    result = [[0] * 3 for _ in range(3)]

    # 转换为灰度图像
    gray_img = img.to_grayscale()

    for i, (x, y, w, h) in enumerate(subgrid_coords):
        subgrid_img = gray_img.copy().crop((x, y, w, h))

        # 计算小方格中心点的坐标
        center_x = w // 2
        center_y = h // 2

        # 获取中心点的灰度值
        center_gray_value = get_gray_value(subgrid_img, center_x, center_y)

        # 判断灰度值
        if center_gray_value < 50:  # 判断是否为黑子
            result[i // 3][i % 3] = 2  # 黑子
            img.draw_rectangle(x, y, w, h, color=(255, 255, 255))  # 白色矩形标记
            img.draw_string(x + 10, y + 10, 'Black', color=(255, 255, 255))  # 白色文字
        elif center_gray_value > 200:  # 判断是否为白子
            result[i // 3][i % 3] = 0 # 白子
            img.draw_rectangle(x, y, w, h, color=(0, 0, 0))  # 黑色矩形标记
            img.draw_string(x + 10, y + 10, 'White', color=(0, 0, 0))  # 黑色文字
        else:
            result[i // 3][i % 3] = 1  # 无子
            img.draw_rectangle(x, y, w, h, color=(0, 0, 0))  # 黑色矩形标记
            img.draw_string(x + 10, y + 10, 'None', color=(0, 0, 0))  # 黑色文字

    return result

# 主循环
while True:
    clock.tick()


    img = sensor.snapshot()

    # 获取中心区域的坐标和尺寸
    center_grid_coords = get_center_grid_coords()

    # 获取9个小方格的坐标
    subgrid_coords = get_subgrid_coords(*center_grid_coords)

    # 识别颜色并分类棋子
    grid_result = classify_subgrids(img, subgrid_coords)


    # 打印棋盘状态
    for row in grid_result:
        chessboard.append(row[0])
        chessboard.append(row[1])
        chessboard.append(row[2])
        print(row)

    # LCD显示图片
    lcd.display(img)
    print(chessboard)
    sending_data(chessboard[0],chessboard[1],chessboard[2],chessboard[3],chessboard[4],chessboard[5],chessboard[6],chessboard[7],chessboard[8])
#    img_data=bytearray([0x2C,0x12,chessboard[0],chessboard[1],chessboard[2],chessboard[3],chessboard[4],chessboard[5],chessboard[6],chessboard[7],chessboard[8],0x5B])
#    uart_A.write(img_data)
    chessboard=[]
    # 打印FPS
#    print(clock.fps())
