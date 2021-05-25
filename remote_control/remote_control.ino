#define BLINKER_WIFI
#include <Blinker.h>
 
char auth[] = "f3b19b38b8ca";//这里面填写设备的密钥
char ssid[] = "iap";//这里填写你的wifi名字
char pswd[] = "iapiapiap";//这里填写你的WiFi密码

// 新建组件对象
BlinkerButton Button1("btn-abc");
 
// 按下按键即会执行该函数
void button1_callback(const String & state) {
    BLINKER_LOG("get button state: ", state);
    if (state=="on") {
        digitalWrite(13, LOW);
        // 反馈开关状态
        Button1.print("on");
    } else if(state=="off"){
        digitalWrite(13, HIGH);
        // 反馈开关状态
        Button1.print("off");
    }
}
 
void setup() {
    // 初始化串口
    Serial.begin(115200);
    // 初始化有LED的IO
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    // 初始化blinker
    Blinker.begin(auth, ssid, pswd);      //连接wifi
    Button1.attach(button1_callback);     //获取按键
}
 
void loop() {
    Blinker.run();
}
