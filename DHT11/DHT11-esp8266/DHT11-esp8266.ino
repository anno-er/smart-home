#define BLINKER_WIFI
 
#include <Blinker.h>
#include <DHT.h>
 
char auth[] = "f3b19b38b8ca";//这里面填写设备的密钥
char ssid[] = "iap";//这里填写你的wifi名字
char pswd[] = "iapiapiap";//这里填写你的WiFi密码

BlinkerButton Button1("btn-abc");
 


BlinkerNumber HUMI("humi");
BlinkerNumber TEMP("temp");

#define DHTPIN 2  //接的是GPIO2端口 D4
 
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
 
DHT dht(DHTPIN, DHTTYPE);
 
float humi_read = 0, temp_read = 0;

void button1_callback(const String & state) {
    BLINKER_LOG("get button state: ", state);
    digitalWrite(13,!digitalRead(13));
}
 


 
void heartbeat()
{
    //反馈湿度数据
    HUMI.print(humi_read);
    //反馈温度数据
    TEMP.print(temp_read);
}
 
void setup()
{
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);
    BLINKER_DEBUG.debugAll();
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
 
    Blinker.begin(auth, ssid, pswd);
    Button1.attach(button1_callback);
    Blinker.attachHeartbeat(heartbeat);
    dht.begin();
}
 
void loop()
{
    Blinker.run();
 
    float h = dht.readHumidity();
    float t = dht.readTemperature();
 
    if (isnan(h) || isnan(t))
    {
        BLINKER_LOG("Failed to read from DHT sensor!");
    }
    else
    {
        BLINKER_LOG("Humidity: ", h, " %");
        BLINKER_LOG("Temperature: ", t, " *C");
        humi_read = h;
        temp_read = t;
    }
 
    Blinker.delay(2000);
}
