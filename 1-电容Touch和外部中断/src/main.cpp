#include <Arduino.h>

// �����ⲿ�жϵ�Mode
// 0�����жϣ���ȡTouchֵ
// 1��Touch�жϣ�ִ��TouchEvent()
// 2���ⲿIO���ж�
# define EXT_ISR_MODE   2

// �¼��жϺ���
void TouchEvent(){

  // ���ڴ�ӡ
  Serial.printf("Touch Event.\r\n");
}

// �¼��жϺ���
void PinIntEvent(){

  // ���ڴ�ӡ
  Serial.printf("PinInt Event.\r\n");
}

void setup()
{
  // put your setup code here, to run once:

  // ��ʼ������
  Serial.begin(115200);

# if 1 == EXT_ISR_MODE
  // Pin:T0(GPIO4), ����ָ��:touchEvent, ��ֵ��40
  touchAttachInterrupt(T0, TouchEvent, 40);       // GPIO0 �¼��жϺ��� (Touch)��ֵΪ40�����¼�

# elif 2 == EXT_ISR_MODE      // �����ⲿ�ж�
  pinMode(0, INPUT_PULLUP);
  attachInterrupt(0, PinIntEvent, FALLING);     // ���� �¼��жϺ��� �½��ش���

# endif
}

void loop()
{
  // put your main code here, to run repeatedly:
# if  0 == EXT_ISR_MODE
  Serial.printf("touch:%d\r\n", touchRead(T0));       // ��ȡGPIO4 ��ֵ

# endif

  delay(200);
}
