# include "bsp_sg90.h"

int freq = 50;          // Ƶ��(20ms)����
int channel = 8;        // ͨ��(����ͨ��(0 ~ 7)��80MHzʱ������������ͨ��(8 ~ 15)��1MHz ʱ������)
int resolution = 8;     // �ֱ���
const int led = 4;

static int calculatePWM(int degree){

    // 0 - 180 ��
    // 20ms ���ڣ��ߵ�ƽ0.5-2.5ms����Ӧ0-180�Ƕ�
    const float deadZone = 6.4;     // ��Ӧ0.5ms (0.5ms / 256)
    const float max = 32;           // ��Ӧ2.5ms (2.5ms / 256)

    if (degree < 0) {

        degree = 0;
    }
    if (degree > 180) {

        degree = 180;
    }

    return (int)(((max - deadZone) / 180) * degree + deadZone);
}

void MyPWM_Init(void){

    ledcSetup(channel, freq, resolution);       // ����ͨ��
    ledcAttachPin(led, channel);                // ����ͨ������
}

void MyPWM_Drive(void){

    for (int d = 0; d <= 180; d += 60){

        ledcWrite(channel, calculatePWM(d));    // ���PWM
        Serial.printf("value = %d   calcu = %d\r\n", d, calculatePWM(d));
        delay(1000);
    }
}
