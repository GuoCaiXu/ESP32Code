#include <Arduino.h>

// 定义外部中断的Mode
// 0：无中断，读取Touch值
// 1：Touch中断，执行TouchEvent()
// 2：外部IO的中断
# define EXT_ISR_MODE   2

// 事件中断函数
void TouchEvent(){

  // 串口打印
  Serial.printf("Touch Event.\r\n");
}

// 事件中断函数
void PinIntEvent(){

  // 串口打印
  Serial.printf("PinInt Event.\r\n");
}

void setup()
{
  // put your setup code here, to run once:

  // 初始化串口
  Serial.begin(115200);

# if 1 == EXT_ISR_MODE
  // Pin:T0(GPIO4), 函数指针:touchEvent, 阈值：40
  touchAttachInterrupt(T0, TouchEvent, 40);       // GPIO0 事件中断函数 (Touch)阈值为40触发事件

# elif 2 == EXT_ISR_MODE      // 触发外部中断
  pinMode(0, INPUT_PULLUP);
  attachInterrupt(0, PinIntEvent, FALLING);     // 引脚 事件中断函数 下降沿触发

# endif
}

void loop()
{
  // put your main code here, to run repeatedly:
# if  0 == EXT_ISR_MODE
  Serial.printf("touch:%d\r\n", touchRead(T0));       // 读取GPIO4 的值

# endif

  delay(200);
}
