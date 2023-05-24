# include "bsp_sg90.h"

int freq = 50;          // 频率(20ms)周期
int channel = 8;        // 通道(高速通道(0 ~ 7)由80MHz时钟驱动，低速通道(8 ~ 15)由1MHz 时钟驱动)
int resolution = 8;     // 分辨率
const int led = 4;

static int calculatePWM(int degree){

    // 0 - 180 度
    // 20ms 周期，高电平0.5-2.5ms，对应0-180角度
    const float deadZone = 6.4;     // 对应0.5ms (0.5ms / 256)
    const float max = 32;           // 对应2.5ms (2.5ms / 256)

    if (degree < 0) {

        degree = 0;
    }
    if (degree > 180) {

        degree = 180;
    }

    return (int)(((max - deadZone) / 180) * degree + deadZone);
}

void MyPWM_Init(void){

    ledcSetup(channel, freq, resolution);       // 设置通道
    ledcAttachPin(led, channel);                // 设置通道引脚
}

void MyPWM_Drive(void){

    for (int d = 0; d <= 180; d += 60){

        ledcWrite(channel, calculatePWM(d));    // 输出PWM
        Serial.printf("value = %d   calcu = %d\r\n", d, calculatePWM(d));
        delay(1000);
    }
}
