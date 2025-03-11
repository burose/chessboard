# 24-电赛-E三子棋

#### 介绍
本项目是针对2024年全国大学生电子设计竞赛E题的解决方案。该项目通过STM32C8T6微控制器控制三轴机械臂，结合K210进行棋盘与棋子的识别，实现了棋子的精准移动和放置。项目中使用了OLED屏幕显示实时状态，串口通信与K210进行数据交互，PWM信号控制舵机实现机械臂的运动。

#### 功能特点
硬件控制：
使用STM32C8T6作为主控芯片。
三轴机械臂通过舵机控制，能够精确移动棋子。
气泵用于吸取和放下棋子。
图像识别：
使用K210进行棋盘与棋子的识别，提供坐标信息。
屏幕显示：
OLED屏幕显示当前棋盘状态、机械臂状态和调试信息。
通信与控制：
通过串口通信与K210进行数据交换。
PWM输出控制舵机运动。
已解决问题
在比赛过程中，曾遇到放下棋子后由于磕碰导致棋子位移的问题，现已通过优化算法和改进机械结构解决了此问题。


#### 软件架构
主要模块说明
OLED显示模块：

负责实时显示棋盘状态、机械臂坐标和调试信息。
PWM控制模块：

生成PWM波形，控制舵机的角度和运动。
串口通信模块：

与K210进行数据通信，接收棋盘和棋子的识别结果。
机械臂控制模块：

根据K210返回的坐标信息，计算机械臂的运动轨迹，控制棋子移动。
气泵控制模块：

控制气泵的开关，实现棋子的吸取和放置。

文件功能说明
main.c：主程序入口，负责初始化各个模块并启动运行。
oled.c：OLED屏幕驱动程序，负责显示信息。
pwm.c：PWM生成程序，控制舵机。
serial.c：串口通信程序，接收K210的数据。
......

#### 硬件说明
主要硬件组件
STM32C8T6最小系统板：

主控芯片，负责控制机械臂、气泵和串口通信。
三轴机械臂：

由三个舵机驱动，能够精确移动棋子。
K210图像识别模块：

用于识别棋盘和棋子的位置，通过串口将坐标信息发送给STM32。
OLED屏幕：

显示当前棋盘状态、机械臂状态和调试信息。
气泵：

用于吸取和释放棋子。
硬件连接
STM32C8T6与K210：通过串口通信（TX/RX）。
STM32C8T6与机械臂：通过PWM信号控制舵机。
STM32C8T6与气泵：通过GPIO控制气泵的开关。
STM32C8T6与OLED：通过I2C或SPI接口连接。

#### 安装教程

开发环境
软件工具：

Keil uVision5（用于编写和编译STM32代码）。
MaixPy IDE（用于开发K210的图像识别程序）。
硬件准备：

STM32C8T6最小系统板。
K210模块。
OLED屏幕（I2C接口）。
三轴机械臂。
气泵及相关控制电路。
安装步骤
STM32代码编译：

克隆本仓库到本地。
使用Keil uVision5打开项目文件（.uvprojx）。
配置Keil的编译选项，确保选择正确的STM32C8T6芯片型号。
编译并下载程序到STM32开发板。
K210代码烧录：

使用MaixPy IDE打开K210的脚本（k210_chess_recognition.py）。
编译并上传到K210模块。
硬件连接：

按照硬件连接部分的说明，将各个模块正确连接。
确保电源电压符合要求。
启动运行：

上电后，程序将自动运行。
观察OLED屏幕的显示内容，确保系统正常工作。

#### 使用说明
启动系统：

上电后，系统会自动初始化机械臂、OLED和K210模块。
初始化完成后，K210会开始识别棋盘和棋子的位置。
棋子移动：

系统接收到K210发送的坐标信息后，会控制机械臂移动到指定位置。
气泵会吸取棋子并将其放置到目标位置。
调试信息：

通过OLED屏幕可以查看当前的棋盘状态、机械臂坐标和其他调试信息。



