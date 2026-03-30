
//建议WiFi设置空白，这样就可以使用Hotspot或AirKiss配网(AirKiss配网，手机连接2.4G网络，关注公众号“易艾思”，菜单点击更多->嵌入设备配网，靠近设备进行配网)
const char *WiFi_ssid = "";            //WiFi名称Damon Ivy Guest 2.4G
const char *WiFi_key = "";             //WiFi密码1357924680
const String SYSModel = "OmniTally";   //硬件
const String SYSVer = "2.2.26010819";  //版本

#define WIFI_CONNECT_WAIT 15            //WiFi连接等待秒数
#define WIFI_CONFIG_WAIT 180            //WiFi配置等待秒数
#define WIFI_SLEEP_TIME 180             //WiFi休眠时间秒数
#define WIFI_WAKEUP_TIME 3600           //WiFi唤醒时间秒数
#define WEBSOCKETS_SERVER_CLIENT_MAX 8  //WebSocket最大连接数
#define RESCUE_TIMES 5                  //救援模式重启次数

uint8_t SYSDebug = 1;        //调试
uint8_t WiFiConfigType = 2;  //WiFi配置方式  //1=AirKiss,2=Hotspot

//以下为配置默认值
uint8_t Tally_ID = 1;                  //TallyID台历灯号
uint8_t Tally_Style = 1;               //Tally显示风格  //1=全屏,2=小方块,3=空方块,3=实心圆,5=空心圆,6=爱心,7=数字亮字,8=数字底亮,9=指示器
uint8_t RGB_Brightnes = 128;           //Tally主灯亮灯亮度
uint8_t RGB_Darkness = 16;             //Tally主灯灭灯亮度
uint8_t RGB_Background = 4;            //Tally主灯背景亮度
uint8_t RGBsub_Brightnes = 128;        //Tally副灯亮度
uint8_t Switcher_Type = 0;             //切换台品牌 //0=未设置,1=OSEE,2=vMix,3=BMD,4=芯象
String Switcher_IP = "0.0.0.0";        //切换台IP
String OmniTally_IP = "0.0.0.0";       //OmniTally IP
String OmniTally_Gateway = "0.0.0.0";  //OmniTally Gateway
String OmniTally_Subnet = "0.0.0.0";   //OmniTally Subnet
uint8_t Info_Brightnes = 0;            //提示灯亮度 0跟随RGB_Brightnes
unsigned int Web_Port = 80;
unsigned int Socket_Port = 81;
unsigned int Udp_Port = 60081;


//以下为硬件配置默认值
uint8_t Pin_LED = 2;       //LED指示灯针脚GPIO2 D4
uint8_t Pin_RGB = 255;     //主RGB灯组针脚GPIO4 D2
uint8_t Pin_KEY = 255;     //按键针脚GPIO0 D3
uint8_t Pin_RGBsub = 255;  //副RGB灯组针脚GPIO5 D1
uint8_t Pin_BATT = 255;    //电池电压检测脚GPIO17 A0(D1模块:10K接正30K接负 ESP模块:100K接正30K接负)
uint8_t Pin_PVW = 255;     //PVW灯针脚	GPIO12 D6
uint8_t Pin_PGM = 255;     //PGM灯针脚	GPIO13 D7

uint8_t RGBsub_Pixel = 1;  //副RGB灯组灯珠数量

//5*5矩阵
uint8_t RGB_Pixel = 25;            //RGB灯组灯珠数量
uint8_t RGB_Matrix_PixelX = 5;     //RGB灯组矩阵水平灯珠数量
uint8_t RGB_Matrix_PixelY = 5;     //RGB灯组矩阵垂直灯珠数量
uint8_t RGB_Matrix_OffsetX = 0;    //RGB灯组矩阵水平偏移量
uint8_t RGB_Matrix_OffsetY = 0;    //RGB灯组矩阵水平偏移量
uint8_t RGB_Matrix_Direction = 2;  //RGB灯组矩阵排列方向 //1=水平左右,2=反Z字排列
/*
//8*8矩阵
uint8_t RGB_Pixel=64; //RGB灯组灯珠数量
uint8_t RGB_Matrix_PixelX=8;      //RGB灯组矩阵水平灯珠数量
uint8_t RGB_Matrix_PixelY=8;      //RGB灯组矩阵垂直灯珠数量
uint8_t RGB_Matrix_OffsetX=2;     //RGB灯组矩阵水平偏移量
uint8_t RGB_Matrix_OffsetY=2;     //RGB灯组矩阵水平偏移量
uint8_t RGB_Matrix_Direction=1;   //RGB灯组矩阵排列方向 //1=水平左右,2=反Z字排列
*/


//以下为内部变量不要修改
uint8_t SYSChk = 0;                //随机数
String Hardware = ARDUINO_BOARD;   //硬件类型
String WiFiMAC = "";               //设备MAC
String WiFiIP = "";                //设备IP
uint16_t WiFiConnectCount = 0;     //WiFi连接计数器
uint16_t WiFiConfigCount = 0;      //WiFi配置计数器
uint16_t WiFiSleepCount = 0;       //WiFiSleep计数器
uint16_t WiFiWakeupCount = 0;      //WiFiWakeup计数器
uint8_t RescueCount = 0;           //Rescue计数器
uint8_t LoopCount = 0;             //Loop计数器
uint8_t TickerCountS = 0;          //TickS计数器
uint8_t TickerCountSlast = 0;      //上次TickS计数器
uint8_t TickerCountmS = 0;         //TickmS计数器
uint8_t FlickerCount = 0;          //Flicker计数器
uint8_t UpdateCount = 0;           //Update计数器
uint8_t ConnectCountdown = 0;      //Connect计数器
uint8_t WebSocketStatus = 0;       //Socket状态
uint8_t LastTcping = 0;            //上次Tcping
uint8_t SwitcherPVW = 0;           //当前PVW
uint8_t SwitcherPGM = 0;           //当前PGM
uint8_t SwitcherPVWlast = 0;       //上次PVW
uint8_t SwitcherPGMlast = 0;       //上次PGM
uint8_t PixelCount = 0;            //亮灯计数器
float BatteryVoltage = 0;          //电池电压
float BatteryPercent = 0;          //电池电量
uint32_t BatteryColor = 0x008080;  //电压颜色
//((电压-3.0V)/(4.2V-3.0V))*100%


/*
0 Config
1 Pin_LED
2 Pin_RGB
3 Pin_KEY
4 Pin_BATT
5 RGB_Pixel
6 RGB_Matrix_PixelX
7 RGB_Matrix_PixelY
8 RGB_Matrix_OffsetX
9 RGB_Matrix_OffsetY
10 RGB_Matrix_Direction
11 Tally_ID
12 Tally_Style
13 RGB_Brightnes
14 RGB_Darkness
15 RGB_Background
16 Switcher_Type
17 Switcher_IP1
18 Switcher_IP2
19 Switcher_IP3
20 Switcher_IP4
21 Pin_RGBsub
22 RGBsub_Pixel
23 Pin_PVW
24 Pin_PGM
25 RGBsub_Brightnes
99 RescueCount
*/


#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESP8266httpUpdate.h>
#include <ESP8266HTTPClient.h>

#include <DNSServer.h>
DNSServer dnsServer;

#include <ESP8266WebServer.h>
ESP8266WebServer server(Web_Port);

#include <WebSocketsServer.h>
WebSocketsServer WebSocket = WebSocketsServer(Socket_Port);

#include <WiFiUdp.h>
WiFiUDP udpTally;
WiFiUDP udp;
const uint8_t udpTallyHeader[] = { 0x4F, 0x6D, 0x6E, 0x69, 0x54, 0x61, 0x6C, 0x6C, 0x79 };
const uint8_t udpHeader[] = { 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0xF7, 0xC2, 0x00 };
uint8_t udpBuffer[255];
char udppacketBuffer[512];
bool udpBegun = false;

#include <NTPClient.h>
WiFiUDP udpNTP;
NTPClient timeClient(udpNTP, "ntp.aliyun.com", 60 * 60 * 8, 1000 * WIFI_WAKEUP_TIME / 2);
uint8_t TimeH = 0;
uint8_t TimeM = 0;
uint8_t TimeS = 0;

#include "OneButton.h"
OneButton Abutton(Pin_KEY);

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(RGB_Pixel, Pin_RGB, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripsub = Adafruit_NeoPixel(RGBsub_Pixel, Pin_RGBsub, NEO_GRB + NEO_KHZ800);

#include <ArduinoJson.h>
StaticJsonDocument<256> doc;
StaticJsonDocument<256> json;
StaticJsonDocument<256> jsons;

#include <WiFiClient.h>
WiFiClient client;
WiFiClient tcping;

#include <Ticker.h>
Ticker tickerS;
Ticker tickermS;

#include "ATEMbase.h"
#include "ATEMstd.h"
ATEMstd AtemSwitcher;

const byte digit5x5[10][8] = {  //5*5非居中
  { 0x30, 0x48, 0x48, 0x48, 0x30, 0x00, 0x00, 0x00 },  // 0
  { 0x20, 0x60, 0x20, 0x20, 0x70, 0x00, 0x00, 0x00 },  // 1
  { 0x70, 0x08, 0x30, 0x40, 0x78, 0x00, 0x00, 0x00 },  // 2
  { 0x70, 0x08, 0x30, 0x08, 0x70, 0x00, 0x00, 0x00 },  // 3
  { 0x48, 0x48, 0x38, 0x08, 0x08, 0x00, 0x00, 0x00 },  // 4
  { 0x78, 0x40, 0x70, 0x08, 0x70, 0x00, 0x00, 0x00 },  // 5
  { 0x30, 0x40, 0x70, 0x48, 0x30, 0x00, 0x00, 0x00 },  // 6
  { 0x78, 0x08, 0x10, 0x20, 0x20, 0x00, 0x00, 0x00 },  // 7
  { 0x30, 0x48, 0x30, 0x48, 0x30, 0x00, 0x00, 0x00 },  // 8
  { 0x30, 0x48, 0x78, 0x08, 0x30, 0x00, 0x00, 0x00 }   // 9
};
/*
const byte digit5x5[10][8] = { //5*5全幅
  { 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00 },  // 0
  { 0x20, 0x60, 0x20, 0x20, 0x70, 0x00, 0x00, 0x00 },  // 1
  { 0xF0, 0x08, 0x70, 0x80, 0xF8, 0x00, 0x00, 0x00 },  // 2
  { 0xF0, 0x08, 0x70, 0x08, 0xF0, 0x00, 0x00, 0x00 },  // 3
  { 0x90, 0x90, 0xF8, 0x10, 0x10, 0x00, 0x00, 0x00 },  // 4
  { 0xF8, 0x80, 0xF0, 0x08, 0xF0, 0x00, 0x00, 0x00 },  // 5
  { 0x70, 0x80, 0xF0, 0x88, 0x70, 0x00, 0x00, 0x00 },  // 6
  { 0xF8, 0x08, 0x10, 0x20, 0x40, 0x00, 0x00, 0x00 },  // 7
  { 0x70, 0x88, 0x70, 0x88, 0x70, 0x00, 0x00, 0x00 },  // 8
  { 0x70, 0x88, 0x78, 0x08, 0x70, 0x00, 0x00, 0x00 }   // 9
};
const byte digit5x5[10][8] = { //3*5瘦长
  { 0x70, 0x50, 0x50, 0x50, 0x70, 0x00, 0x00, 0x00 },  // 0
  { 0x20, 0x60, 0x20, 0x20, 0x70, 0x00, 0x00, 0x00 },  // 1
  { 0x70, 0x10, 0x70, 0x40, 0x70, 0x00, 0x00, 0x00 },  // 2
  { 0x70, 0x10, 0x70, 0x10, 0x70, 0x00, 0x00, 0x00 },  // 3
  { 0x50, 0x50, 0x70, 0x10, 0x10, 0x00, 0x00, 0x00 },  // 4
  { 0x70, 0x40, 0x70, 0x10, 0x70, 0x00, 0x00, 0x00 },  // 5
  { 0x70, 0x40, 0x70, 0x50, 0x70, 0x00, 0x00, 0x00 },  // 6
  { 0x70, 0x10, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00 },  // 7
  { 0x70, 0x50, 0x70, 0x50, 0x70, 0x00, 0x00, 0x00 },  // 8
  { 0x70, 0x50, 0x70, 0x10, 0x70, 0x00, 0x00, 0x00 }   // 9
};
*/
const byte matrix[5][8] = {
  { 0x00, 0x70, 0x70, 0x70, 0x00, 0x00, 0x00, 0x00 },  // 方块
  { 0xf8, 0x88, 0x88, 0x88, 0xf8, 0x00, 0x00, 0x00 },  // 空方块
  { 0x70, 0xF8, 0xF8, 0xF8, 0x70, 0x00, 0x00, 0x00 },  // 实心圆
  { 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00 },  // 空心圆
  { 0x50, 0xF8, 0xF8, 0x70, 0x20, 0x00, 0x00, 0x00 }   // 爱心
};


void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(SYSModel + " Ver:" + SYSVer);

  rst_info *resetInfo = ESP.getResetInfoPtr();
  debug("ResetInfo:" + String(resetInfo->reason) + " " + ESP.getResetInfo() + " " + ESP.getResetReason());

  SYSChk = random(1, 254);

  EEPROM.begin(128);
  Config_Load();
  Rescue_Check(0);

  if (Pin_LED != 255) { pinMode(Pin_LED, OUTPUT); }
  if (Pin_PVW != 255) { pinMode(Pin_PVW, OUTPUT); }
  if (Pin_PGM != 255) { pinMode(Pin_PGM, OUTPUT); }

  if (Pin_KEY != 255) {
    pinMode(Pin_KEY, INPUT_PULLUP);

    Abutton = OneButton(Pin_KEY);
    Abutton.reset();
    Abutton.attachClick(AClick);
    Abutton.attachDoubleClick(AdoubleClick);
    Abutton.attachLongPressStart(ALongPressStart, &Abutton);
    Abutton.attachDuringLongPress(ADuringLongPress, &Abutton);
    Abutton.attachLongPressStop(ALongPressStop, &Abutton);
  }


  System_BatteryVoltage();

  tickerS.attach(1, tickerFunS);
  tickermS.attach_ms(25, tickerFunmS);

  if ((Pin_RGB != 255) && (RGB_Pixel > 0)) {
    strip.begin();
    strip.setPin(Pin_RGB);
    strip.updateLength(RGB_Pixel);
    strip.clear();
    strip.setBrightness(128);
    strip.fill(strip.Color(Info_Brightnes, Info_Brightnes, Info_Brightnes), 0, RGB_Pixel);
    strip.show();
    strip.setBrightness(255);
  }

  if ((Pin_RGBsub != 255) && (RGBsub_Pixel > 0)) {
    stripsub.begin();
    stripsub.setPin(Pin_RGBsub);
    stripsub.updateLength(RGBsub_Pixel);
    stripsub.clear();
    stripsub.setBrightness(128);
    stripsub.fill(stripsub.Color(Info_Brightnes, Info_Brightnes, Info_Brightnes), 0, RGBsub_Pixel);
    stripsub.show();
    stripsub.setBrightness(255);
  }

  WiFi_Connect();

  Web_Server();

  if (Tally_Style < 10) {
    client.setTimeout(3000);
    tcping.setTimeout(3000);

    WebSocket.begin();
    WebSocket.onEvent(WebSocket_Event);

  } else if (Tally_Style == 10) {
    timeClient.begin();
    TimeSync();
  }
}


void loop() {
  LoopCount++;

  if (Tally_Style < 10) {
    switch (Switcher_Type) {
      case 1:
        Switcher_OSEEv2();
        break;

      case 2:
        Switcher_vMix();
        break;

      case 3:
        Switcher_BMD();
        break;

      case 4:
        Switcher_NAYA();
        break;

      case 5:
        Switcher_NAYA();
        break;

      case 8:
        Switcher_OSEE();
        break;

      case 9:
        Switcher_OmniTally();
        break;
    }

    Tally_Light(0);


  } else if (Tally_Style == 10) {
    if (TickerCountSlast != TickerCountS) {  //秒触发
      TickerCountSlast = TickerCountS;

      WiFi_Saving(0);
      TimeSync();
      TimeShow();
    }
  }

  Abutton.tick();
  WebSocket.loop();
  server.handleClient();
  MDNS.update();
}


bool tickerFunS() {
  TickerCountS++;
  //debug("TickerS " + String(TickerCountS));
  //debug(WiFiMAC + " - " + WiFiIP + " - " + String(SwitcherPVW) + "/" + String(SwitcherPGM) + " - " + String(TickerCountS));

  if (TickerCountS > 5) { Rescue_Check(1); }

  if (TickerCountS % 5 == 0) {
    if (WiFi.status() == WL_CONNECTED) {
      WiFiIP = WiFi.localIP().toString();
    } else {
      WiFiIP = "0.0.0.0";
    }
    WebSocket_Send();
  }


  if (WiFiConnectCount == 0) {
    if (Tally_Style == 10) {
    }
  }


  if (UpdateCount > 0) {
    UpdateCount++;
    if (UpdateCount > 60) {
      ESP.restart();
    }
  }


  if (ConnectCountdown > 0) { ConnectCountdown--; }
  if (WiFiConfigCount == 0) {  //正常连接
    if (Pin_LED != 255) { digitalWrite(Pin_LED, !digitalRead(Pin_LED)); }
    System_BatteryVoltage();
  }


  if (TickerCountS % 60 == 0) {
    debug("ResourceInfo:" + String(ESP.getHeapFragmentation()) + " " + String(ESP.getFreeHeap()) + " " + String(ESP.getMaxFreeBlockSize()));
  }

  return true;
}




bool tickerFunmS() {
  TickerCountmS++;
  //debug("TickermS " + String(TickerCountmS));

  if ((Switcher_Type > 0) && (Switcher_Type < 255) && (TickerCountmS % 20 == 0)) {
    Udp_Send(0);
  }

  if (FlickerCount > 0) {
    FlickerCount--;
    if (Pin_LED != 255) { digitalWrite(Pin_LED, !digitalRead(Pin_LED)); }
    //debug(".");
  }

  return true;
}




void Switcher_OSEEv2() {
  if (!udpBegun) {
    udp.begin(19018);
    udpBegun = true;
  }
  int packetSize = udp.parsePacket();
  if (packetSize) {
    //Serial.print(packetSize);
    //Serial.print(udp.remoteIP());
    //Serial.println(udp.remotePort());

    int len = udp.read(udppacketBuffer, sizeof(udppacketBuffer) - 1);
    if (len > 0) {
      udppacketBuffer[len] = '\0'; // 添加字符串结束符
      //Serial.println(udppacketBuffer);
      Switcher_OSEEv2_parseUDPData(udppacketBuffer);
    }
  }
}


void Switcher_OSEEv2_parseUDPData(const char* data) {
  StaticJsonDocument<256> doc;

  if (deserializeJson(doc, data)) return;

  String id = doc["id"].as<String>();
  JsonArray values = doc["value"];

  String result = "";
  for (size_t i = 0; i < values.size(); i++) {
    if (i > 0) result += "|";
    result += String(values[i].as<int>());
  }

  if (id == "pgmTally") {
    SwitcherPGM=result.toInt();
  }
  else if (id == "pvwTally") {
    SwitcherPVW = result.toInt();
  }
}


String OSEE_data;
String OSEE_BlockJson[32];
uint8_t OSEE_BlockCount = 0;
void Switcher_OSEE() {
  if (client.connected()) {
    if ((TickerCountS % 5 == 0) && (LastTcping != TickerCountS)) {
      debug("Switcher_OSEE TCPing");
      LastTcping = TickerCountS;
      if (!TCPing(Switcher_IP, 19010)) {
        client.stop();
      }
    }
    if (client.available()) {
      debug("Switcher_OSEE Receive");
      do {
        char response = client.read();
        OSEE_data = OSEE_data + response;
      } while (client.available());
      Switcher_OSEE_PreJson(OSEE_data);
      if (OSEE_BlockCount > 0) {
        for (uint8_t i = 1; i <= OSEE_BlockCount; i++) {
          debug("Switcher_OSEE JSON:" + OSEE_BlockJson[i]);
          //Serial.println(OSEE_BlockJson[i]);
          deserializeJson(json, OSEE_BlockJson[i]);
          if (json["id"] == "pgmIndex") {
            SwitcherPGM = uint8_t(json["value"][0]) + 1;
          }
          if (json["id"] == "pvwIndex") {
            SwitcherPVW = uint8_t(json["value"][0]) + 1;
          }
        }
        LED_Flicker();
        OSEE_BlockCount = 0;
      }
    }

  } else {
    if (Switcher_IP != "0.0.0.0") {
      if (ConnectCountdown == 0) {
        ConnectCountdown = 5;
        debug("Switcher_OSEE Connecting");
        if (!client.connect(Switcher_IP, 19010)) {
          debug("Switcher_OSEE Connection failed");
        }
      }
    }
  }
}

void Switcher_OSEE_PreJson(String &input) {
  int start = 0;
  int end = 0;
  String output;
  for (int i = 0; i < input.length(); i++) {
    char c = input[i];
    if (isPrintable(c) || c == '{' || c == '}' || c == '[' || c == ']') {
      output += c;
    }
  }
  while ((start = output.indexOf('{', start)) >= 0) {
    end = output.indexOf('}', start) + 1;
    if (end > start) {
      OSEE_BlockJson[++OSEE_BlockCount] = output.substring(start, end);
      start = end;
    } else {
      break;
    }
  }
  if (start > 0 && start < output.length()) {
    input = output.substring(start);
  } else {
    input = "";
  }
}



void Switcher_vMix() {
  delay(25);
  if (LoopCount % 10 == 0) {

    if ((Switcher_IP != "0.0.0.0") && (WiFi.status() == WL_CONNECTED)) {
      HTTPClient http;
      http.setTimeout(3000);
      http.begin(client, "http://" + Switcher_IP + ":8088/api/");
      http.addHeader("Content-Type", "text/xml");

      int httpCode = http.GET();
      if (httpCode > 0) {
        LoopCount = 0;
        String payload = http.getString();

        String previewValue = extractTagValue(payload, "<preview>", "</preview>");
        String activeValue = extractTagValue(payload, "<active>", "</active>");

        if (previewValue != "" && activeValue != "") {
          SwitcherPVW = previewValue.toInt();
          SwitcherPGM = activeValue.toInt();
        }
      }
      http.end();
    }
  }
}



void Switcher_BMD() {
  delay(50);
  AtemSwitcher.runLoop();
  if (AtemSwitcher.isConnected()) {
    for (uint8_t i = 1; i <= 8; i++) {
      if (AtemSwitcher.getProgramTally(i)) { SwitcherPGM = i; }
      if (AtemSwitcher.getPreviewTally(i)) { SwitcherPVW = i; }
      //debug("PVW "+String(i)+" - "+String(PreviewTally));
    }

  } else {
    if (LoopCount % 60 == 0) {
      AtemSwitcher.begin(stringToIPAddress(Switcher_IP));
      AtemSwitcher.connect();
    }
  }
}


void Switcher_NAYA() {
  if (!udpBegun) {
    udp.begin(54321);
    udpBegun = true;
  }
  int packetSize = udp.parsePacket();
  if (packetSize) {
    int len = udp.read(udpBuffer, 255);
    if (len > 0) {
      udpBuffer[len] = 0;
    }

    if (len >= 12 && memcmp(udpBuffer, udpHeader, sizeof(udpHeader)) == 0) {
      uint8_t byte1 = udpBuffer[9];   // 00
      uint8_t byte2 = udpBuffer[10];  // 80
      uint8_t byte3 = udpBuffer[11];  // 01
      uint32_t data24bit = (byte1 << 16) | (byte2 << 8) | byte3;

      uint16_t pvw12bit = (data24bit >> 12) & 0xFFF;
      uint16_t pgm12bit = data24bit & 0xFFF;

      uint8_t pvw = 0;
      uint8_t pgm = 0;

      for (int i = 0; i < 12; i++) {
        if (pvw12bit & (1 << i)) {
          pvw = i + 1;
          break;
        }
      }

      for (int i = 0; i < 12; i++) {
        if (pgm12bit & (1 << i)) {
          pgm = i + 1;
          break;
        }
      }

      SwitcherPVW = pvw;
      SwitcherPGM = pgm;
    }
  }
}


void Switcher_OmniTally() {
  if (!udpBegun) {
    udp.begin(Udp_Port);
    udpBegun = true;
  }

  int packetSize = udp.parsePacket();
  if (packetSize > 0) {
    int headerLen = sizeof(udpTallyHeader);
    int len = udp.read(udpBuffer, sizeof(udpBuffer));
    if (len >= headerLen + 2) {
      bool headerMatch = true;
      for (int i = 0; i < headerLen; i++) {
        if (udpBuffer[i] != udpTallyHeader[i]) {
          headerMatch = false;
          break;
        }
      }
      if (headerMatch) {
        uint8_t pvw = udpBuffer[headerLen];
        uint8_t pgm = udpBuffer[headerLen + 1];
        SwitcherPVW = pvw;
        SwitcherPGM = pgm;
      } else {
        memset(udpBuffer, 0, sizeof(udpBuffer));
      }
    }
  }
}






void Tally_Light(uint8_t force) {
  if ((!force) && ((SwitcherPVWlast == SwitcherPVW) && (SwitcherPGMlast == SwitcherPGM))) { return; }
  debug("Tally:" + String(SwitcherPVW) + "-" + String(SwitcherPGM));
  Udp_Send(1);
  WebSocket_Send();
  LED_Flicker();
  SwitcherPVWlast = SwitcherPVW;
  SwitcherPGMlast = SwitcherPGM;
  uint8_t yml = Tally_ID;
  uint32_t color;

  if (Pin_PVW != 255) {
    if (Tally_ID == SwitcherPVW) {
      digitalWrite(Pin_PVW, HIGH);
    } else {
      digitalWrite(Pin_PVW, LOW);
    }
  }

  if (Pin_PGM != 255) {
    if (Tally_ID == SwitcherPGM) {
      digitalWrite(Pin_PGM, HIGH);
    } else {
      digitalWrite(Pin_PGM, LOW);
    }
  }

  if (RGBsub_Pixel > 0) {
    if (Tally_ID == SwitcherPGM) {
      stripsub.fill(stripsub.Color(RGBsub_Brightnes, 0, 0), 0, RGBsub_Pixel);
      stripsub.show();
    } else if (Tally_ID == SwitcherPVW) {
      stripsub.fill(stripsub.Color(0, RGBsub_Brightnes, 0), 0, RGBsub_Pixel);
      stripsub.show();
    } else {
      stripsub.fill(stripsub.Color(0, 0, 0), 0, RGBsub_Pixel);
      stripsub.show();
    }
  }

  if (RGB_Pixel > 0) {
    switch (Tally_Style) {
      case 1:
        if (Tally_ID == SwitcherPGM) {
          strip.fill(strip.Color(RGB_Brightnes, 0, 0), 0, RGB_Pixel);
          strip.show();
        } else if (Tally_ID == SwitcherPVW) {
          strip.fill(strip.Color(0, RGB_Brightnes, 0), 0, RGB_Pixel);
          strip.show();
        } else {
          strip.fill(strip.Color(RGB_Darkness, RGB_Darkness, RGB_Darkness), 0, RGB_Pixel);
          strip.show();
        }
        break;

      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
        yml = Tally_Style - 2;
        if (Tally_ID == SwitcherPGM) {
          color = strip.Color(RGB_Brightnes, 0, 0);
        } else if (Tally_ID == SwitcherPVW) {
          color = strip.Color(0, RGB_Brightnes, 0);
        } else {
          color = strip.Color(RGB_Darkness, RGB_Darkness, RGB_Darkness);
        }
        for (uint8_t y = 1; y <= RGB_Matrix_PixelY; y++) {
          byte bit = matrix[yml][y - 1 - RGB_Matrix_OffsetY];
          for (uint8_t x = 1; x <= RGB_Matrix_PixelX; x++) {
            //Serial.print(bitRead(bit, 8-x) ? '*' : ' ');
            //Serial.print("("+String(y-1-RGB_Matrix_OffsetY)+","+String(8-x+RGB_Matrix_OffsetX)+")");
            if ((8 - x + RGB_Matrix_OffsetX >= 0) && (y - 1 - RGB_Matrix_OffsetY >= 0) && (bitRead(bit, 8 - x + RGB_Matrix_OffsetX))) {
              strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, color);
            } else {
              strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, strip.Color(0, RGB_Background, RGB_Background));
            }
          }
          strip.show();
        }

        break;


      case 7:
        if (Tally_ID == SwitcherPGM) {
          color = strip.Color(RGB_Brightnes, 0, 0);
        } else if (Tally_ID == SwitcherPVW) {
          color = strip.Color(0, RGB_Brightnes, 0);
        } else {
          color = strip.Color(RGB_Darkness, RGB_Darkness, RGB_Darkness);
        }
        for (int y = 1; y <= RGB_Matrix_PixelY; y++) {
          byte bit = digit5x5[yml][y - 1 - RGB_Matrix_OffsetY];
          for (int x = 1; x <= RGB_Matrix_PixelX; x++) {
            //Serial.print(bitRead(bit, 8-x) ? '*' : ' ');
            if ((8 - x + RGB_Matrix_OffsetX >= 0) && (y - 1 - RGB_Matrix_OffsetY >= 0) && (bitRead(bit, 8 - x + RGB_Matrix_OffsetX))) {
              if (RGB_Matrix_Direction == 2) {
                if (y % 2 == 1) {  //正向行
                  strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + RGB_Matrix_PixelX - x, color);
                } else {
                  strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, color);
                }
              } else {
                strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, color);
              }
            } else {
              if (RGB_Matrix_Direction == 2) {
                if (y % 2 == 1) {  //正向行
                  strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + RGB_Matrix_PixelX - x, strip.Color(0, RGB_Background, RGB_Background));
                } else {
                  strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, strip.Color(0, RGB_Background, RGB_Background));
                }
              } else {
                strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, strip.Color(0, RGB_Background, RGB_Background));
              }
            }
          }
          strip.show();
        }

        break;


      case 8:
        if (Tally_ID == SwitcherPGM) {
          color = strip.Color(RGB_Brightnes, 0, 0);
        } else if (Tally_ID == SwitcherPVW) {
          color = strip.Color(0, RGB_Brightnes, 0);
        } else {
          color = strip.Color(RGB_Darkness, RGB_Darkness, RGB_Darkness);
        }
        for (int y = 1; y <= RGB_Matrix_PixelY; y++) {
          byte bit = digit5x5[yml][y - 1 - RGB_Matrix_OffsetY];
          for (int x = 1; x <= RGB_Matrix_PixelX; x++) {
            //Serial.print(bitRead(bit, 8-x) ? '*' : ' ');
            if ((8 - x + RGB_Matrix_OffsetX >= 0) && (y - 1 - RGB_Matrix_OffsetY >= 0) && (bitRead(bit, 8 - x + RGB_Matrix_OffsetX))) {
              if (RGB_Matrix_Direction == 2) {
                if (y % 2 == 1) {  //正向行
                  strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + RGB_Matrix_PixelX - x, strip.Color(0, RGB_Background, RGB_Background));
                } else {
                  strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, strip.Color(0, RGB_Background, RGB_Background));
                }
              } else {
                strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, strip.Color(0, RGB_Background, RGB_Background));
              }
            } else {
              if (RGB_Matrix_Direction == 2) {
                if (y % 2 == 1) {  //正向行
                  strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + RGB_Matrix_PixelX - x, color);
                } else {
                  strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, color);
                }
              } else {
                strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, color);
              }
            }
          }
          strip.show();
        }

        break;


      case 9:  //PGM指示
        yml = SwitcherPGM;
        color = strip.Color(RGB_Brightnes, 0, 0);
        for (int y = 1; y <= RGB_Matrix_PixelY; y++) {
          byte bit = digit5x5[yml][y - 1 - RGB_Matrix_OffsetY];
          for (int x = 1; x <= RGB_Matrix_PixelX; x++) {
            //Serial.print(bitRead(bit, 8-x) ? '*' : ' ');
            if ((8 - x + RGB_Matrix_OffsetX >= 0) && (y - 1 - RGB_Matrix_OffsetY >= 0) && (bitRead(bit, 8 - x + RGB_Matrix_OffsetX))) {
              if (RGB_Matrix_Direction == 2) {
                if (y % 2 == 1) {  //正向行
                  strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + RGB_Matrix_PixelX - x, color);
                } else {
                  strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, color);
                }
              } else {
                strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, color);
              }
            } else {
              if (RGB_Matrix_Direction == 2) {
                if (y % 2 == 1) {  //正向行
                  strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + RGB_Matrix_PixelX - x, strip.Color(0, RGB_Background, RGB_Background));
                } else {
                  strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, strip.Color(0, RGB_Background, RGB_Background));
                }
              } else {
                strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, strip.Color(0, RGB_Background, RGB_Background));
              }
            }
          }
          strip.show();
        }

        break;


      case 10:


        break;


      default:
        Tally_Style = 1;
        Tally_Light(1);
        break;
    }
  }
}



void Udp_Send(bool showdebug) {
  if (Switcher_Type == 9) { return; }
  udpTally.beginPacket("255.255.255.255", Udp_Port);
  udpTally.write(udpTallyHeader, sizeof(udpTallyHeader));
  udpTally.write(SwitcherPVW);
  udpTally.write(SwitcherPGM);
  udpTally.endPacket();
  if (showdebug) { debug("UDP Send:" + String(SwitcherPVW) + String(SwitcherPGM)); }
}


void WebSocket_Event(uint8_t num, WStype_t type, uint8_t *payload, size_t length) {
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      WebSocketStatus = 0;
      break;
    case WStype_CONNECTED:
      {
        IPAddress ip = WebSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d\n", num, ip[0], ip[1], ip[2], ip[3]);
        //WebSocket.sendTXT(num, "Hello OmniTally !");
        WebSocketStatus = 1;
      }
      break;
    case WStype_TEXT:
      //Serial.printf("[%u] Text message: %s\n", num, payload);
      break;
    case WStype_PONG:
      Serial.printf("[%u] PONG received!\n", num);
      break;
    case WStype_ERROR:
      Serial.println("WebSocket error!");
      break;
  }
}

void WebSocket_Send() {
  if (WebSocketStatus == 1) {
    WebSocketStatus = 2;
    String data = String(SwitcherPVW) + String(SwitcherPGM);
    debug("WebSocket_Send:" + data);
    //debug(WebSocket.connectedClients());
    if (!WebSocket.broadcastTXT(data)) {
      debug("WebSocket Reconnect");
      WebSocket.disconnect();
      WebSocket.begin();
    }
    WebSocketStatus = 1;
  }
}



void Web_Server() {
  debug("WebServer Start");
  server.on("/", handleRoot);
  server.on("/na", handleNA);
  server.on("/pvw", handlePVW);
  server.on("/pgm", handlePGM);
  server.on("/api", handleApi);
  server.on("/setup", handleSetup);
  server.on("/config", handleConfig);
  server.on("/restart", System_Restart);
  server.on("/wificonfig", handleWiFiConfig);
  server.on("/wificonnect", handleWiFiConnect);
  server.onNotFound(handleWildcard);
  server.begin();
}

void handleRoot() {
  LED_Flicker();
  server.send(200, "text/html", "<html><head><title>" + SYSModel + "™</title><meta http-equiv='Content-Type' content='text/html; charset=utf-8' /></head><b>Hello " + SYSModel + " !</b><br><br>TallyID: " + String(Tally_ID) + "<br><br>\n<small>作者: 无所不能的大孟(OmniDamon)<br>\n版本: " + SYSVer + "<br>\nMAC: " + WiFiMAC + "<br>\nIP: " + WiFiIP + "<br>\n电池: " + String(BatteryVoltage, 2) + "V (" + String(BatteryPercent, 2) + "%)</small><br>\n<script src='http://omni.aidns.net/OmniTally/appcall.js'></script>\n</html>");
}



void handleSetup() {
  LED_Flicker();
  //替换" \"
  String html = "<!DOCTYPE html><html><head><title>{SYSModel}™ Setup</title><meta http-equiv='Content-Type' content='text/html; charset=utf-8' /><meta http-equiv='Pragma' content='no-cache' /><meta http-equiv='Cache-Control' content='no-cache' /><meta http-equiv='Expires' content='0' /><meta name='viewport' content='width=device-width, initial-scale=1, maximum-scale=2, user-scalable=1'><style>table,th,td {border: 1px solid #999999;border-collapse: collapse;}input[type='number'] {text-align: right;}span{font-size:12px;}</style></head><body style='color:#333333;background:#ffffff;'><left><b>{SYSModel}™ Setup</b><br><table><input id='i0' type='hidden'><tr><td colspan='2'><b>基本设置</b> <small><input type='checkbox' id='autosave' value='1'>实时更新保存</small></td></tr><tr><td>TallyID</td><td><select id='i11' size='1' oninput='change()'><option value='1'>1</option><option value='2'>2</option><option value='3'>3</option><option value='4'>4</option><option value='5'>5</option><option value='6'>6</option><option value='7'>7</option><option value='8'>8</option></select></td></tr><tr><td>主灯显示风格</td><td><select id='i12' size='1' oninput='change()'><option value='1'>全亮</option><option value='2'>小方块</option><option value='3'>空方块</option><option value='4'>实心圆</option><option value='5'>空心圆</option><option value='6'>爱心</option><option value='7'>数字正显</option><option value='8'>数字反显</option><option value='9'>PGM指示</option><option value='10'>时钟</option></select></td></tr><tr><td>主灯激活亮度</td><td><input id='i13' type='range' min='0' max='255' step='1' style='width:255px;' onmouseup='change()'onchange='change()' oninput='dispval(this,\"d13\")'><span id='d13'>-</span></td></tr><tr><td>主灯未激活亮度</td><td><input id='i14' type='range' min='0' max='255' step='1' style='width:255px;' onmouseup='change()'onchange='change()' oninput='dispval(this,\"d14\")'><span id='d14'>-</span></td></tr><tr><td>主灯背景亮度</td><td><input id='i15' type='range' min='0' max='255' step='1' style='width:255px;' onmouseup='change()'onchange='change()' oninput='dispval(this,\"d15\")'><span id='d15'>-</span></td></tr><tr><td>副灯亮度</td><td><input id='i25' type='range' min='0' max='255' step='1' style='width:255px;' onmouseup='change()'onchange='change()' oninput='dispval(this,\"d25\")'><span id='d25'>-</span></td></tr><tr><td>切换台品牌</td><td><select id='i16' size='1'><option value='0'>(未选择)</option><option value='1'>OSEE 时代奥视</option><option value='8'>OSEE 时代奥视(旧)</option><option value='2'>vMix 软导播</option><option value='3'>BMD ATEM</option><option value='4'>SINSAM 芯象</option><option value='5'>NAYA 纳雅</option><option value='9'>OmniTally</option></select></td></tr><tr><td>切换台IP</td><td><input id='i17' type='number' min='0' max='255' step='1'>.<input id='i18' type='number' min='0' max='255'step='1'>.<input id='i19' type='number' min='0' max='255' step='1'>.<input id='i20' type='number' min='0'max='255' step='1'></td></tr><tr><td colspan='2'><b>硬件设置</b></td></tr><tr><td>LED针脚</td><td><select id='i1' size='1'><option value='255'>(不启用)</option><option value='16'>D0 GPIO16</option><option value='5'>D1 GPIO5</option><option value='4'>D2 GPIO4</option><option value='0'>D3 GPIO0</option><option value='2'>D4 GPIO2</option><option value='14'>D5 GPIO14</option><option value='12'>D6 GPIO12</option><option value='13'>D7 GPIO13</option><option value='15'>D8 GPIO15</option></select> (默认D4 GPIO2)</td></tr><tr><td>主RGB针脚</td><td><select id='i2' size='1'><option value='255'>(不启用)</option><option value='16'>D0 GPIO16</option><option value='5'>D1 GPIO5</option><option value='4'>D2 GPIO4</option><option value='0'>D3 GPIO0</option><option value='2'>D4 GPIO2</option><option value='14'>D5 GPIO14</option><option value='12'>D6 GPIO12</option><option value='13'>D7 GPIO13</option><option value='15'>D8 GPIO15</option></select> (默认D2 GPIO4)</td></tr><tr><td>按键针脚</td><td><select id='i3' size='1'><option value='255'>(不启用)</option><option value='16'>D0 GPIO16</option><option value='5'>D1 GPIO5</option><option value='4'>D2 GPIO4</option><option value='0'>D3 GPIO0</option><option value='2'>D4 GPIO2</option><option value='14'>D5 GPIO14</option><option value='12'>D6 GPIO12</option><option value='13'>D7 GPIO13</option><option value='15'>D8 GPIO15</option></select> (默认D3 GPIO0)</td></tr><tr><td>电量针脚</td><td><select id='i4' size='1'><option value='255'>(不启用)</option><option value='17'>ADC A0</option></select> (默认ADC A0)</td></tr><tr><td>副RGB针脚</td><td><select id='i21' size='1'><option value='255'>(不启用)</option><option value='16'>D0 GPIO16</option><option value='5'>D1 GPIO5</option><option value='4'>D2 GPIO4</option><option value='0'>D3 GPIO0</option><option value='2'>D4 GPIO2</option><option value='14'>D5 GPIO14</option><option value='12'>D6 GPIO12</option><option value='13'>D7 GPIO13</option><option value='15'>D8 GPIO15</option></select> (默认D1 GPIO5)</td></tr><tr><td>PVW针脚</td><td><select id='i23' size='1'><option value='255'>(不启用)</option><option value='16'>D0 GPIO16</option><option value='5'>D1 GPIO5</option><option value='4'>D2 GPIO4</option><option value='0'>D3 GPIO0</option><option value='2'>D4 GPIO2</option><option value='14'>D5 GPIO14</option><option value='12'>D6 GPIO12</option><option value='13'>D7 GPIO13</option><option value='15'>D8 GPIO15</option></select> (默认D6 GPIO12)</td></tr><tr><td>PGM针脚</td><td><select id='i24' size='1'><option value='255'>(不启用)</option><option value='16'>D0 GPIO16</option><option value='5'>D1 GPIO5</option><option value='4'>D2 GPIO4</option><option value='0'>D3 GPIO0</option><option value='2'>D4 GPIO2</option><option value='14'>D5 GPIO14</option><option value='12'>D6 GPIO12</option><option value='13'>D7 GPIO13</option><option value='15'>D8 GPIO15</option></select> (默认D7 GPIO13)</td></tr><tr><td>主RGB灯珠数</td><td><input id='i5' type='number' min='0' max='255' step='1'></td></tr><tr><td>副RGB灯珠数</td><td><input id='i22' type='number' min='0' max='255' step='1'></td></tr><tr><td>主RGB灯珠排列</td><td><select id='i10' size='1'><option value='255'>(非点阵)</option><option value='1'>自左往右(8*8)</option><option value='2'>反Z字(5*5)</option></select></td></tr><tr><td>主RGB水平灯珠数</td><td><input id='i6' type='number' min='0' max='255' step='1'> (点阵灯适用)</td></tr><tr><td>主RGB垂直灯珠数</td><td><input id='i7' type='number' min='0' max='255' step='1'> (点阵灯适用)</td></tr><tr><td>主RGB水平偏移量</td><td><input id='i8' type='number' min='0' max='255' step='1'> (>5像素点阵适用)</td></tr><tr><td>主RGB垂直偏移量</td><td><input id='i9' type='number' min='0' max='255' step='1'> (>5像素点阵适用)</td></tr></td></tr><tr><td>固件更新URL</td><td><input id='url' type='text' size='32'><button id='but_upgrade' onclick='AjaxDo(\"upgrade\")'>升级</button></td></tr><tr><td align='center'><button onclick='AjaxDo(\"default\")'>重置</button></td><td><button onclick='AjaxDo()'>读取</button>   <button onclick='AjaxDo(\"save\")' id='but_save' disabled>保存</button>   <button onclick='AjaxDo(\"restart\")'>重启</button><small>(重置或修改后请重启)</small></td></tr></table><br><small>作者: 无所不能的大孟(OmniDamon)<br>版本: {SYS_VER}<br>MAC: {WiFi_MAC}<br>IP: {WiFi_IP}<br>电池: {SYS_BATTERY}</small><br><script src='http://omni.aidns.net/OmniTally/appcall.js'></script><br><br><script>function change() {if (document.getElementById('autosave').checked) {AjaxDo('save');}}function dispval(obj1,obj2) {if (obj2){document.getElementById(obj2).innerText=obj1.value;}}function AjaxRequest(data) {var xhr = new XMLHttpRequest();xhr.open('POST', 'http://192.168.2.152/config', true);xhr.setRequestHeader('Content-Type', 'application/json');xhr.send(data);xhr.onreadystatechange = function () {if (xhr.readyState === 4) {if (xhr.status === 200) {document.getElementById('but_save').disabled=false;var j = JSON.parse(xhr.responseText);for (var i in j) {if (j.hasOwnProperty(i)) {if (o = document.getElementById('i' + i)) {o.value = j[i];if (d=document.getElementById('d' + i)){d.innerText=j[i];}}}}if (j['error']) { alert(j['error']); }}}};}function AjaxDo(cmd) {var o;var d = {};d['i0'] = document.getElementById('i0').value;if (!cmd) {AjaxRequest();return;} else if (cmd == 'default') {if (!confirm('是否确认重置为默认值?')) { return false; }} else if (cmd == 'upgrade') {if (!confirm('是否确认更新固件?')) { return false; } else { d['url'] = document.getElementById('url').value; }document.getElementById('but_upgrade').disabled=true;} else if (cmd) {for (var i = 1; i <= 25; i++) {if (o = document.getElementById('i' + i)) {d['i' + i] = o.value;}}}d['cmd'] = cmd;d = JSON.stringify(d);AjaxRequest(d);}AjaxRequest();</script></body></html>";
  html.replace("http://192.168.2.152", "");
  html.replace("{SYSModel}", SYSModel);
  html.replace("{SYS_VER}", SYSVer);
  html.replace("{WiFi_MAC}", WiFiMAC);
  html.replace("{WiFi_IP}", WiFiIP);
  html.replace("{SYS_BATTERY}", String(BatteryVoltage, 2) + "V (" + String(BatteryPercent, 2) + "%)");
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
  server.setContentLength(html.length());
  server.send(200, "text/html", html);
}


void handleApi() {
  LED_Flicker();
  doc.clear();
  JsonObject json = doc.to<JsonObject>();

  json["Tally_ID"] = Tally_ID;
  json["WiFi_MAC"] = WiFiMAC;
  json["WiFi_IP"] = WiFiIP;
  json["Ver"] = SYSVer;
  json["PVW"] = SwitcherPVW;
  json["PGM"] = SwitcherPGM;
  String jsonString;
  serializeJson(doc, jsonString);

  debug("API_Send:" + jsonString);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
  server.send(200, "application/json", jsonString);
}


void handleConfig() {
  LED_Flicker();
  doc.clear();
  JsonObject json = doc.to<JsonObject>();

  if (server.hasArg("plain")) {
    String body = server.arg("plain");
    debug("Config_Receive");
    //Serial.println(body);
    deserializeJson(jsons, body);
    if (uint8_t(jsons["i0"]) != SYSChk) {
      json["error"] = "校验失败!";
    } else if (jsons["cmd"] == "save") {
      if (jsons["i1"]) { Pin_LED = String(jsons["i1"]).toInt(); }
      if (jsons["i2"]) { Pin_RGB = String(jsons["i2"]).toInt(); }
      if (jsons["i3"]) { Pin_KEY = String(jsons["i3"]).toInt(); }
      if (jsons["i4"]) { Pin_BATT = String(jsons["i4"]).toInt(); }
      if (jsons["i5"]) { RGB_Pixel = String(jsons["i5"]).toInt(); }
      if (jsons["i6"]) { RGB_Matrix_PixelX = String(jsons["i6"]).toInt(); }
      if (jsons["i7"]) { RGB_Matrix_PixelY = String(jsons["i7"]).toInt(); }
      if (jsons["i8"]) { RGB_Matrix_OffsetX = String(jsons["i8"]).toInt(); }
      if (jsons["i9"]) { RGB_Matrix_OffsetY = String(jsons["i9"]).toInt(); }
      if (jsons["i10"]) { RGB_Matrix_Direction = String(jsons["i10"]).toInt(); }
      if (jsons["i11"]) { Tally_ID = String(jsons["i11"]).toInt(); }
      if (jsons["i12"]) { Tally_Style = String(jsons["i12"]).toInt(); }
      if (jsons["i13"]) { RGB_Brightnes = String(jsons["i13"]).toInt(); }
      if (jsons["i14"]) { RGB_Darkness = String(jsons["i14"]).toInt(); }
      if (jsons["i15"]) { RGB_Background = String(jsons["i15"]).toInt(); }
      if (jsons["i16"]) { Switcher_Type = String(jsons["i16"]).toInt(); }
      uint8_t Switcher_IP1;
      uint8_t Switcher_IP2;
      uint8_t Switcher_IP3;
      uint8_t Switcher_IP4;
      if (jsons["i17"]) { Switcher_IP1 = String(jsons["i17"]).toInt(); }
      if (jsons["i18"]) { Switcher_IP2 = String(jsons["i18"]).toInt(); }
      if (jsons["i19"]) { Switcher_IP3 = String(jsons["i19"]).toInt(); }
      if (jsons["i20"]) { Switcher_IP4 = String(jsons["i20"]).toInt(); }
      if ((jsons["i17"]) && (jsons["i18"]) && (jsons["i19"]) && (jsons["i20"])) {
        Switcher_IP = String(Switcher_IP1) + "." + String(Switcher_IP2) + "." + String(Switcher_IP3) + "." + String(Switcher_IP4);
      }
      if (jsons["i21"]) { Pin_RGBsub = String(jsons["i21"]).toInt(); }
      if (jsons["i22"]) { RGBsub_Pixel = String(jsons["i22"]).toInt(); }
      if (jsons["i23"]) { Pin_PVW = String(jsons["i23"]).toInt(); }
      if (jsons["i24"]) { Pin_PGM = String(jsons["i24"]).toInt(); }
      if (jsons["i25"]) { RGBsub_Brightnes = String(jsons["i25"]).toInt(); }
      Config_Save(0);
    } else if (jsons["cmd"] == "default") {
      Config_Save(1);
    } else if (jsons["cmd"] == "wifireset") {
      WiFi_Reset();
    } else if (jsons["cmd"] == "restart") {
      System_Restart();
    } else if ((jsons["cmd"] == "upgrade") && (jsons["url"])) {
      Update_Firmware(jsons["url"]);
    }

    Tally_Light(1);
  }

  json["1"] = Pin_LED;
  json["2"] = Pin_RGB;
  json["3"] = Pin_KEY;
  json["4"] = Pin_BATT;
  json["5"] = RGB_Pixel;
  json["6"] = RGB_Matrix_PixelX;
  json["7"] = RGB_Matrix_PixelY;
  json["8"] = RGB_Matrix_OffsetX;
  json["9"] = RGB_Matrix_OffsetY;
  json["10"] = RGB_Matrix_Direction;
  json["11"] = Tally_ID;
  json["12"] = Tally_Style;
  json["13"] = RGB_Brightnes;
  json["14"] = RGB_Darkness;
  json["15"] = RGB_Background;
  json["16"] = Switcher_Type;
  uint8_t IPint[4];
  IP2int(Switcher_IP, IPint);
  json["17"] = IPint[0];
  json["18"] = IPint[1];
  json["19"] = IPint[2];
  json["20"] = IPint[3];
  json["21"] = Pin_RGBsub;
  json["22"] = RGBsub_Pixel;
  json["23"] = Pin_PVW;
  json["24"] = Pin_PGM;
  json["25"] = RGBsub_Brightnes;
  json["0"] = SYSChk;
  String jsonString;
  serializeJson(doc, jsonString);

  debug("Config_Send");
  //Serial.println(jsonString);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
  server.send(200, "application/json", jsonString);
}


void handleNA() {
  SwitcherPVW = 0;
  SwitcherPGM = 0;
  Tally_Light(1);
  server.send(200, "text/plain", "N/A " + String(Tally_ID) + " OK");
}

void handlePVW() {
  SwitcherPVW = Tally_ID;
  SwitcherPGM = 0;
  Tally_Light(1);
  server.send(200, "text/plain", "PVW " + String(Tally_ID) + " OK");
}

void handlePGM() {
  SwitcherPVW = 0;
  SwitcherPGM = Tally_ID;
  Tally_Light(1);
  server.send(200, "text/plain", "PGM " + String(Tally_ID) + " OK");
}

void handleWildcard() {
  String path = server.uri();
  if (path.startsWith("/id/")) {
    String idStr = path.substring(4);
    uint8_t Id = idStr.toInt();
    if (Id > 0) {
      Tally_ID = Id;
      Tally_Light(1);
      Config_Save(0);
      server.send(200, "text/plain", "Tally ID " + String(Tally_ID));
      return;
    }

  } else if (path.startsWith("/tally/")) {
    String idStr = path.substring(7);
    uint8_t Id = idStr.toInt();
    if (Id > 0) {
      String html = "<!DOCTYPE html><html><head><title>{SYSModel}™ WebTally</title><meta http-equiv='Content-Type' content='text/html; charset=utf-8' /><meta http-equiv='Pragma' content='no-cache' /><meta http-equiv='Cache-Control' content='no-cache' /><meta http-equiv='Expires' content='0' /><meta name='viewport' content='width=device-width, initial-scale=1.0'><style>html, body {height: 100%;margin: 0;padding: 0;overflow: hidden;}#display {font-size: 50vw;line-height: 50vh;text-align: center;display: flex;justify-content: center;align-items: center;height: 100vh;width: 100vw;font-weight:bold;}</style></head><body style='background:#666666;'><left><div id='display'>-</div><div style='position:fixed;bottom:0px;width:100%;font-size:11px;text-align:center;'>{SYSModel}™ {SYS_VER} &ensp; 作者: 无所不能的大孟(OmniDamon)</div><script>var Tally_ID='1';var Tally_Server='ws://192.168.2.152:81';document.getElementById('display').innerText=Tally_ID;function connectWebSocket() { socket = new WebSocket(Tally_Server); socket.onopen = function(event) { console.log(\"Connected to WebSocket server.\"); }; socket.onmessage = function(event) { console.log(\"Message from server:\", event.data); var PVW= event.data.charAt(0); var PGM = event.data.charAt(1); if (Tally_ID==PGM ){ document.body.style.backgroundColor = '#ff0000'; }else if (Tally_ID==PVW){ document.body.style.backgroundColor = '#00ff00'; }else{ document.body.style.backgroundColor = '#999999'; } }; socket.onclose = function(event) { console.log(\"Disconnected from WebSocket server.\"); reconnectWebSocket(); }; socket.onerror = function(error) { console.error(\"WebSocket error:\", error); };}function reconnectWebSocket() { setTimeout(function() { console.log(\"Attempting to reconnect...\"); connectWebSocket(); }, 1000);}function refresh() { if (socket.readyState === WebSocket.OPEN) { console.log(\"Sending message:\", Tally_ID); socket.send(Tally_ID); } else { console.log(\"WebSocket is not open. Cannot send message.\"); } setTimeout(refresh, 3000);}connectWebSocket();refresh();</script></body></html>";
      html.replace("Tally_ID='1'", "Tally_ID='" + String(Id) + "'");
      html.replace("Tally_Server='ws://192.168.2.152:81'", "Tally_Server='ws://" + String(WiFiIP) + ":" + String(Socket_Port) + "'");
      html.replace("{SYSModel}", SYSModel);
      html.replace("{SYS_VER}", SYSVer);
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
      server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
      server.send(200, "text/html", html);
    }

  } else {
    server.send(404, "text/plain", "Page Not found !");
  }
}



void handleWiFiConfig() {
  LED_Flicker();
  //替换" \"
  String html = "<!DOCTYPE html><html><head><title>{SYSModel}™ WiFi Config</title><meta http-equiv='Content-Type' content='text/html; charset=utf-8' /><meta http-equiv='Pragma' content='no-cache' /><meta http-equiv='Cache-Control' content='no-cache' /><meta http-equiv='Expires' content='0' /><meta name='viewport' content='width=device-width, initial-scale=1, maximum-scale=2, user-scalable=1'><style>table,th,td {border: 1px solid #999999;border-collapse: collapse;}</style></head><body style='color:#333333;background:#ffffff;'><left><b>{SYSModel}™ WiFi Config</b><br><table width='420'><tr><td width='1%' nowrap>WiFi Station</td><td><select id='ssids' size='1' style='width:250px;height:24px;' onchange='document.getElementById(\"ssid\").value=this.value'><option value=''>(请选择)</option></select><button id='but_scan' onclick='AjaxDo(\"list\")'>搜索</button></td></tr><tr><td>WiFi SSID</td><td><input type='text' name='ssid' id='ssid' size='32' style='width:250px;' value='' onfocus='this.select();'></td></tr><tr><td>WiFi KEY</td><td><input type='text' name='key' id='key' size='32' style='width:250px;' value='' onfocus='this.select();'></td></tr><tr><td align='center'><button id='but_reset' onclick='AjaxDo(\"wifireset\")'>重置</button></td><td><button id='but_connect' onclick='AjaxDo(\"connect\")'>连接</button></td></tr></table><br><small>作者: 无所不能的大孟(OmniDamon)<br>版本: {SYS_VER}<br>MAC: {WiFi_MAC}</small><br><script src='http://omni.aidns.net/OmniTally/appcall.js'></script><br><br><script>function AjaxRequest(data) {var xhr = new XMLHttpRequest();xhr.open('POST', 'http://192.168.2.152/wificonnect', true);xhr.setRequestHeader('Content-Type', 'application/json');xhr.send(data);xhr.onreadystatechange = function () {if (xhr.readyState === 4) {if (xhr.status === 200) {var j = JSON.parse(xhr.responseText);var o=document.getElementById('ssids');o.length=1;if (j['WiFi_List']){for (var i in j['WiFi_List']) {o.options[o.length]=new Option(j['WiFi_List'][i]['ssid']+\" (\"+j['WiFi_List'][i]['rssi']+\"dBm)\" , j['WiFi_List'][i]['ssid']);}}var o=document.getElementById('but_scan');o.textContent=\"搜索\";o.disabled=false;}}};}function AjaxDo(cmd) {var d = {};if (!cmd) {return;} else if (cmd == 'list') {var o=document.getElementById('but_scan');o.textContent=\"搜索中...\";o.disabled=true;} else if (cmd == 'connect') {if (!confirm('是否确认连接?')) { return false; }document.getElementById('but_connect').disabled=true;d['ssid']=document.getElementById('ssid').value;d['key']=document.getElementById('key').value;} else if (cmd == 'wifireset') {if (!confirm('是否确认重置WiFi连接?')) { return false; }document.getElementById('but_reset').disabled=true;}d['cmd'] = cmd;d = JSON.stringify(d);AjaxRequest(d);}</script></body></html>";
  html.replace("http://192.168.2.152", "");
  html.replace("{SYSModel}", SYSModel);
  html.replace("{SYS_VER}", SYSVer);
  html.replace("{WiFi_MAC}", WiFiMAC);
  html.replace("{WiFi_IP}", WiFiIP);
  html.replace("{SYS_BATTERY}", String(BatteryVoltage, 2) + "V (" + String(BatteryPercent, 2) + "%)");
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
  server.setContentLength(html.length());
  server.send(200, "text/html", html);
}

void handleWiFiConnect() {
  LED_Flicker();
  doc.clear();
  JsonObject json = doc.to<JsonObject>();

  if (server.hasArg("plain")) {
    String body = server.arg("plain");
    debug("Connect_Receive");
    //Serial.println(body);
    deserializeJson(jsons, body);
    if (jsons["cmd"] == "list") {
      int numNetworks = WiFi.scanNetworks();
      if (numNetworks > 0) {
        JsonArray wifilist = doc.createNestedArray("WiFi_List");
        for (int i = 0; i < numNetworks; i++) {
          JsonObject wifi = wifilist.createNestedObject();
          wifi["ssid"] = WiFi.SSID(i);
          wifi["rssi"] = WiFi.RSSI(i);
          wifi["encryption"] = WiFi.encryptionType(i);
          wifi["channel"] = WiFi.channel(i);
          debug("WiFi List " + WiFi.SSID(i) + " (" + String(WiFi.RSSI(i)) + "dBm)");
        }
      }

    } else if (jsons["cmd"] == "connect") {
      debug("WiFi_Connect");
      String ssid = jsons["ssid"];
      String key = jsons["key"];
      if (!ssid) { return; }
      debug("SSID:" + ssid);
      debug("KEY:" + key);
      WiFi.persistent(true);
      WiFi.disconnect(true);
      WiFi.mode(WIFI_OFF);
      WiFi.mode(WIFI_STA);
      WiFi.begin(ssid.c_str(), key.c_str());

      LED_OK();
      delay(500);
      ESP.restart();

    } else if (jsons["cmd"] == "wifireset") {
      debug("WiFi_Reset");
      WiFi_Reset();
    }
  }


  String jsonString;
  serializeJson(doc, jsonString);

  debug("API_Send:" + jsonString);
  //Serial.println(jsonString);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
  server.send(200, "application/json", jsonString);
}




void Show_Number(uint8_t yml = 0, uint32_t color = BatteryColor) {
  for (int y = 1; y <= RGB_Matrix_PixelY; y++) {
    byte bit = digit5x5[yml][y - 1 - RGB_Matrix_OffsetY];
    for (int x = 1; x <= RGB_Matrix_PixelX; x++) {
      //Serial.print(bitRead(bit, 8-x) ? '*' : ' ');
      if ((8 - x + RGB_Matrix_OffsetX >= 0) && (y - 1 - RGB_Matrix_OffsetY >= 0) && (bitRead(bit, 8 - x + RGB_Matrix_OffsetX))) {
        if (RGB_Matrix_Direction == 2) {
          if (y % 2 == 1) {  //正向行
            strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + RGB_Matrix_PixelX - x, color);
          } else {
            strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, color);
          }
        } else {
          strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, color);
        }
      } else {
        if (RGB_Matrix_Direction == 2) {
          if (y % 2 == 1) {  //正向行
            strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + RGB_Matrix_PixelX - x, strip.Color(0, 0, 0));
          } else {
            strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, strip.Color(0, 0, 0));
          }
        } else {
          strip.setPixelColor((y - 1) * RGB_Matrix_PixelX + x - 1, strip.Color(0, 0, 0));
        }
      }
    }
    strip.show();
  }
}

void Show_TallyID(unsigned int ms=1000) {
  debug("TallyID:" + String(Tally_ID));
  if ((Pin_RGB != 255) && (RGB_Pixel > 0)) {
    uint32_t color = strip.Color(Info_Brightnes, Info_Brightnes, 0);
    if ((RGB_Matrix_Direction != 255) && (RGB_Matrix_Direction > 0)) {
      Show_Number(Tally_ID, color);
    } else {
      strip.clear();
      strip.fill(color, 0, Tally_ID);
      strip.show();
    }
    delay(ms);
  }
}

void LED_Flicker() {
  FlickerCount = 3;
}

void LED_Flash(int on, int off) {
  if (Pin_LED != 255) { digitalWrite(Pin_LED, LOW); }
  if (RGB_Pixel == 1) {
    strip.setPixelColor(0, BatteryColor);
    strip.show();
  }
  if (RGBsub_Pixel > 0) {
    stripsub.fill(BatteryColor, 0, RGBsub_Pixel);
    stripsub.show();
  }
  delay(on);
  if (Pin_LED != 255) { digitalWrite(Pin_LED, HIGH); }
  if (RGB_Pixel == 1) {
    strip.setPixelColor(0, strip.Color(0, 0, 0));
    strip.show();
  }
  if (RGBsub_Pixel > 0) {
    stripsub.fill(stripsub.Color(0, 0, 0), 0, RGBsub_Pixel);
    stripsub.show();
  }
  delay(off);
}

void LED_OK() {
  if (Pin_LED != 255) { digitalWrite(Pin_LED, LOW); }
  if (RGB_Pixel > 0) {
    strip.clear();
    strip.fill(stripsub.Color(0, Info_Brightnes, 0), 0, RGB_Pixel);
    strip.show();
  }
  if (RGBsub_Pixel > 0) {
    stripsub.clear();
    stripsub.fill(stripsub.Color(0, Info_Brightnes, 0), 0, RGBsub_Pixel);
    stripsub.show();
  }
  delay(100);
}

void LED_Error() {
  if (Pin_LED != 255) { digitalWrite(Pin_LED, LOW); }
  if (RGB_Pixel > 0) {
    strip.clear();
    strip.fill(stripsub.Color(Info_Brightnes, 0, 0), 0, RGB_Pixel);
    strip.show();
  }
  if (RGBsub_Pixel > 0) {
    stripsub.clear();
    stripsub.fill(stripsub.Color(Info_Brightnes, 0, 0), 0, RGBsub_Pixel);
    stripsub.show();
  }
  delay(200);
}




void AClick() {
  if (Tally_Style == 10) {
    WiFi_Saving(1);
  }

  Tally_Style++;
  Tally_Light(1);
  debug("Aclick,Tally_Style:" + String(Tally_Style));
}
void AdoubleClick() {
  Tally_ID++;
  if (Tally_ID > 8) { Tally_ID = 1; }
  debug("AdoubleClick,Tally_ID:" + String(Tally_ID));
  Show_TallyID(500);
  Tally_Light(1);
}
void ALongPressStart(void *oneButton) {
  int longtime = ((OneButton *)oneButton)->getPressedMs();
  debug("ADuringLongPressStart");
}
void ADuringLongPress(void *oneButton) {
  int longtime = ((OneButton *)oneButton)->getPressedMs();
  RGB_Brightnes += 1;
  if (RGB_Brightnes > 255) { RGB_Brightnes = 1; }
  debug("ADuringLongPress,Brightnes:" + String(RGB_Brightnes));
  Tally_Light(1);
}
void ALongPressStop(void *oneButton) {
  int longtime = ((OneButton *)oneButton)->getPressedMs();
  debug("ADuringLongStop");
  debug(longtime);
  if (WiFiConfigCount != 0) {
    WiFiConfigType++;
    if (WiFiConfigType > 2) { WiFiConfigType = 1; }
    WiFi_Config();
  }
}



void TimeSync() {
  if (WiFi.status() == WL_CONNECTED) {
    if (timeClient.update()) {
      debug("TimeSync OK");
      if (WiFiSleepCount > WIFI_SLEEP_TIME) {
        WiFiWakeupCount = 0;
        WiFi_Off();
      }
    }
  }
  TimeH = timeClient.getHours();
  TimeM = timeClient.getMinutes();
  TimeS = timeClient.getSeconds();
}

void TimeShow() {
  TimeS++;
  if (TimeS > 59) {
    TimeS = 0;
    TimeM++;
  }
  if (TimeM > 59) {
    TimeM = 0;
    TimeH++;
  }
  if (TimeH > 23) { TimeH = 0; }
  //debug("Time:" + String(TimeH) + ":" + String(TimeM) + ":" + String(TimeS));

  strip.clear();
  strip.fill(strip.Color(RGB_Background, RGB_Background, RGB_Background), 0, RGB_Pixel);
  strip.setPixelColor(0, strip.Color(0, 0, RGB_Darkness));
  strip.setPixelColor(3, strip.Color(0, 0, RGB_Darkness));
  strip.setPixelColor(6, strip.Color(0, 0, RGB_Darkness));
  strip.setPixelColor(9, strip.Color(0, 0, RGB_Darkness));

  uint8_t h = (TimeH > 12 ? TimeH - 12 : TimeH);
  strip.setPixelColor(h, strip.Color(RGB_Brightnes, 0, 0));
  uint8_t m = ceil(TimeM / 5);
  strip.setPixelColor(m, (h == m ? strip.Color(RGB_Brightnes, RGB_Brightnes, 0) : strip.Color(0, RGB_Brightnes, 0)));
  uint8_t s = ceil(TimeS / 5);
  if ((s == h) || (s == m) || (s % 3 == 0)) {
    uint32_t color = strip.getPixelColor(s);
    uint8_t r = (color >> 16) & 0xFF;
    uint8_t g = (color >> 8) & 0xFF;
    uint8_t b = color & 0xFF;
    //debug(String(r) + " " + String(g) + " " + String(b));
    float factor = 1.5;
    r = min((uint8_t)(RGB_Brightnes / factor) + (uint8_t)(r * factor), 255);
    g = min((uint8_t)(RGB_Brightnes / factor) + (uint8_t)(g * factor), 255);
    b = min((uint8_t)(RGB_Brightnes / factor) + (uint8_t)(b * factor), 255);
    //debug(String(r) + " " + String(g) + " " + String(b));
    strip.setPixelColor(s, strip.Color(r, g, b));
  } else {
    strip.setPixelColor(s, strip.Color(RGB_Brightnes, RGB_Brightnes, RGB_Brightnes));
  }

  strip.show();
}




bool WiFi_Connect() {
  debug("WiFi Connect");
  WiFiConnectCount++;
  WiFiMAC = WiFi.macAddress();
  WiFiMAC.replace(":", "");
  WiFi.mode(WIFI_OFF);
  WiFi.setAutoConnect(true);
  if (WiFi_ssid == "") {
    debug("WiFi SSID:" + WiFi.SSID());
    WiFi.begin();
  } else {
    debug("WiFi SSID:" + String(WiFi_ssid));
    WiFi.begin(WiFi_ssid, WiFi_key);
  }

  uint8_t Config = EEPROM.read(0);
  if (Config == 1) {
    WiFi.hostname(SYSModel + "-" + WiFiMAC);
    MDNS.begin(SYSModel + "-" + WiFiMAC);
  } else {
    WiFi.hostname(SYSModel);
    MDNS.begin(SYSModel);
  }

  while (WiFi.status() != WL_CONNECTED) {
    LED_Flash(100, 100);

    if (RGB_Pixel > 1) {
      strip.clear();
      strip.setPixelColor((PixelCount < RGB_Pixel ? PixelCount : (RGB_Pixel - 1) * 2 - PixelCount), BatteryColor);
      strip.show();
      if (PixelCount++ >= (RGB_Pixel - 1) * 2) { PixelCount = 0; }
    }

    if (WiFiConnectCount % 5 == 0) { debug("WiFi Connect"); }
    if (WiFiConnectCount++ > 5 * WIFI_CONNECT_WAIT) { break; }  //连接等待
  }

  if (WiFi.status() == WL_CONNECTED) {
    WiFiConnectCount = 0;
    WiFiIP = WiFi.localIP().toString();
    debug("WiFi Connect:OK");
    //LED_OK();
    Show_TallyID();
    Tally_Light(1);

  } else {
    LED_Error();
    WiFiIP = "0.0.0.0";
    debug("WiFi Connect:NK");
    WiFi_Config();
  }

  debug("WiFi MAC:" + WiFiMAC);
  debug("WiFi IP:" + WiFiIP);

  return true;
}


void WiFi_Config() {
  debug("WiFi Config");
  WiFi.mode(WIFI_OFF);
  WiFi.stopSmartConfig();
  if (WiFiConfigType == 1) {
    WiFi_SmartConfig();
  } else {
    WiFi_HotspotConfig();
  }
}


void WiFi_SmartConfig() {
  debug("WiFi SmartConfig");
  WiFi.mode(WIFI_STA);
  WiFi.beginSmartConfig();
  WiFiConfigCount = 0;
  while (1) {
    Abutton.tick();
    if (WiFi.smartConfigDone()) {
      WiFiConfigCount = 0;
      debug("WiFi SmartConfig:OK");
      debug("SSID:" + String(WiFi.SSID().c_str()));
      debug("KEY:" + String(WiFi.psk().c_str()));
      LED_OK();
      delay(1000);
      ESP.restart();
      break;
    }
    BatteryColor = strip.Color(0, 128, 128);
    LED_Flash(150, 350);

    if (RGB_Pixel > 1) {
      strip.clear();
      strip.setPixelColor((PixelCount < RGB_Pixel ? PixelCount : (RGB_Pixel - 1) * 2 - PixelCount), BatteryColor);
      strip.show();
      if (PixelCount++ >= (RGB_Pixel - 1) * 2) { PixelCount = 0; }
    }

    if (WiFiConfigCount % 2 == 0) { debug("WiFi SmartConfig"); }
    if (WiFiConfigCount++ > 2 * WIFI_CONFIG_WAIT) {  //smart配网等待
      WiFiConfigCount = 0;
      debug("WiFi SmartConfig:NK");
      LED_Error();
      delay(1000);
      ESP.restart();
      break;
    }
  }
}


void WiFi_HotspotConfig() {
  debug("WiFi HotspotConfig");
  WiFi.mode(WIFI_AP);
  WiFi.softAP(SYSModel + "-" + WiFiMAC);
  WiFi.softAPConfig(IPAddress(192, 168, 7, 1), IPAddress(192, 168, 7, 1), IPAddress(255, 255, 255, 0));
  dnsServer.start(53, "*", WiFi.softAPIP());
  server.stop();
  delay(100);
  server.on("/", handleWiFiConfig);
  server.on("/wificonfig", handleWiFiConfig);
  server.on("/wificonnect", handleWiFiConnect);
  server.begin();
  debug("IP:" + WiFi.softAPIP().toString());
  WiFiConfigCount = 0;
  while (1) {
    Abutton.tick();
    dnsServer.processNextRequest();
    server.handleClient();

    delay(5);
    if (WiFiConfigCount % 160 == 0) {
      BatteryColor = strip.Color(0, 128, 128);
      LED_Flash(100, 100);

      if (RGB_Pixel > 1) {
        strip.clear();
        strip.setPixelColor((PixelCount < RGB_Pixel ? PixelCount : (RGB_Pixel - 1) * 2 - PixelCount), BatteryColor);
        strip.show();
        if (PixelCount++ >= (RGB_Pixel - 1) * 2) { PixelCount = 0; }
      }

      debug("WiFi HotspotConfig");
    }
    if (WiFiConfigCount++ > 160 * WIFI_CONFIG_WAIT) {  //hotspot配网等待
      WiFiConfigCount = 0;
      debug("WiFi HotspotConfig:NK");
      LED_Error();
      delay(1000);
      ESP.restart();
      break;
    }
  }
}


void WiFi_Reset() {
  debug("WiFi Reset");
  WiFi.persistent(true);
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  WiFi.mode(WIFI_STA);
  String ssid = "OmniTally";
  String key = "1357924680";
  debug("SSID:" + ssid);
  debug("KEY:" + key);
  WiFi.persistent(true);
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), key.c_str());
  LED_OK();
  delay(500);
  ESP.restart();
}

void WiFi_Off() {
  debug("WiFi Off");
  WiFi.forceSleepBegin();
  delay(10);
}

void WiFi_On() {
  debug("WiFi On");
  WiFi.forceSleepWake();
  delay(10);
  WiFi.mode(WIFI_STA);
  WiFi.begin();
}


void WiFi_Saving(uint8_t onoff) {
  //debug("WiFi Saving:" + String(WiFiSleepCount) + "-" + String(WiFiWakeupCount));
  if (onoff == 1) {
    WiFiSleepCount = 0;
    if (WiFi.getMode() == WIFI_OFF) {
      WiFi_On();
    }
  }
  if (WiFiSleepCount <= WIFI_SLEEP_TIME) { WiFiSleepCount++; }
  if (WiFiSleepCount == WIFI_SLEEP_TIME) {
    WiFiWakeupCount = 0;
    WiFi_Off();
  }
  if (WiFi.getMode() == WIFI_OFF) {
    if (WiFiWakeupCount <= WIFI_WAKEUP_TIME) { WiFiWakeupCount++; }
    if (WiFiWakeupCount == WIFI_WAKEUP_TIME) {
      WiFi_On();
    }
  }
}




void Config_Load() {
  debug("Config_Load");
  uint8_t Config = EEPROM.read(0);
  if (Config == 1) {
    Pin_LED = EEPROM.read(1);
    Pin_RGB = EEPROM.read(2);
    Pin_KEY = EEPROM.read(3);
    Pin_BATT = EEPROM.read(4);
    RGB_Pixel = EEPROM.read(5);
    RGB_Matrix_PixelX = EEPROM.read(6);
    RGB_Matrix_PixelY = EEPROM.read(7);
    RGB_Matrix_OffsetX = EEPROM.read(8);
    RGB_Matrix_OffsetY = EEPROM.read(9);
    RGB_Matrix_Direction = EEPROM.read(10);
    Tally_ID = EEPROM.read(11);
    Tally_Style = EEPROM.read(12);
    RGB_Brightnes = EEPROM.read(13);
    RGB_Darkness = EEPROM.read(14);
    RGB_Background = EEPROM.read(15);
    Switcher_Type = EEPROM.read(16);
    uint8_t Switcher_IP1 = EEPROM.read(17);
    uint8_t Switcher_IP2 = EEPROM.read(18);
    uint8_t Switcher_IP3 = EEPROM.read(19);
    uint8_t Switcher_IP4 = EEPROM.read(20);
    Switcher_IP = String(Switcher_IP1) + "." + String(Switcher_IP2) + "." + String(Switcher_IP3) + "." + String(Switcher_IP4);
    Pin_RGBsub = EEPROM.read(21);
    RGBsub_Pixel = EEPROM.read(22);
    Pin_PVW = EEPROM.read(23);
    Pin_PGM = EEPROM.read(24);
    RGBsub_Brightnes = EEPROM.read(25);
  }
  if (Info_Brightnes == 0) { Info_Brightnes = RGB_Brightnes; }
}


void Config_Save(uint8_t rest) {
  debug("Config_Save");
  if (rest == 1) {
    EEPROM.write(0, 0);
    EEPROM.write(99, 0);
    EEPROM.commit();
    return;
  }
  EEPROM.write(0, 1);
  EEPROM.write(1, Pin_LED);
  EEPROM.write(2, Pin_RGB);
  EEPROM.write(3, Pin_KEY);
  EEPROM.write(4, Pin_BATT);
  EEPROM.write(5, RGB_Pixel);
  EEPROM.write(6, RGB_Matrix_PixelX);
  EEPROM.write(7, RGB_Matrix_PixelY);
  EEPROM.write(8, RGB_Matrix_OffsetX);
  EEPROM.write(9, RGB_Matrix_OffsetY);
  EEPROM.write(10, RGB_Matrix_Direction);
  EEPROM.write(11, Tally_ID);
  EEPROM.write(12, Tally_Style);
  EEPROM.write(13, RGB_Brightnes);
  EEPROM.write(14, RGB_Darkness);
  EEPROM.write(15, RGB_Background);
  EEPROM.write(16, Switcher_Type);
  uint8_t IPint[4];
  IP2int(Switcher_IP, IPint);
  EEPROM.write(17, IPint[0]);
  EEPROM.write(18, IPint[1]);
  EEPROM.write(19, IPint[2]);
  EEPROM.write(20, IPint[3]);
  EEPROM.write(21, Pin_RGBsub);
  EEPROM.write(22, RGBsub_Pixel);
  EEPROM.write(23, Pin_PVW);
  EEPROM.write(24, Pin_PGM);
  EEPROM.write(25, RGBsub_Brightnes);
  EEPROM.commit();

  if (udpBegun) {
    udp.stop();
    udpBegun = false;
  }
}


void Rescue_Check(bool rest) {
  RescueCount = EEPROM.read(99);
  if (rest) {
    if (RescueCount == 1) { return; }
    RescueCount = 0;
  }
  if (RescueCount == 255) { RescueCount = 0; }
  RescueCount++;
  debug("RescueCount:" + String(RescueCount));
  if ((RESCUE_TIMES > 0) && (RescueCount > RESCUE_TIMES)) {
    debug("Rescue");
    Config_Save(1);
    WiFi_Reset();
  }
  EEPROM.write(99, RescueCount);
  EEPROM.commit();
}


float System_BatteryVoltage() {
  BatteryColor = strip.Color(0, Info_Brightnes, Info_Brightnes);
  if (Pin_BATT == 255) {
    BatteryVoltage = 0;
  } else {
    int adcValue = analogRead(Pin_BATT);  // 读取 ADC 值
    float adcgene = 0.0041;               // ADC因子(适用于带分压电阻的D1模块)
    BatteryVoltage = adcValue * adcgene;  // 计算电池电压
    BatteryPercent = ((BatteryVoltage - 3.0) / (4.2 - 3.0)) * 100;
    BatteryPercent = constrain(BatteryPercent, 0, 100);
    if (BatteryVoltage >= 3.9) {
      BatteryColor = strip.Color(0, Info_Brightnes, 0);
    } else if (BatteryVoltage >= 3.3) {
      BatteryColor = strip.Color(Info_Brightnes, Info_Brightnes, 0);
    } else if (BatteryVoltage >= 2.5) {
      BatteryColor = strip.Color(Info_Brightnes, 0, 0);
    }
    if ((BatteryVoltage > 2) && (BatteryVoltage < 3)) {  //低电压休眠
      System_Shutdown();
    }
  }
  return BatteryVoltage;
}



void System_Restart() {
  debug("System Restart");
  ESP.restart();
}


void System_Shutdown() {
  debug("System Shutdown");
  if (RGB_Pixel > 0) {
    strip.clear();
    strip.setBrightness(0);
    strip.show();
  }
  if (RGBsub_Pixel > 0) {
    stripsub.clear();
    stripsub.setBrightness(0);
    stripsub.show();
  }
  ESP.deepSleep(0);
}



void Update_Firmware(String url) {
  debug("Update Firmware " + url);
  UpdateCount = 1;
  ESPhttpUpdate.setClientTimeout(6000);
  ESPhttpUpdate.setLedPin(Pin_LED, LOW);
  ESPhttpUpdate.onStart(update_started);
  ESPhttpUpdate.onEnd(update_finished);
  ESPhttpUpdate.onProgress(update_progress);
  ESPhttpUpdate.onError(update_error);
  t_httpUpdate_return ret = ESPhttpUpdate.update(client, url);
  switch (ret) {
    case HTTP_UPDATE_FAILED: Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s\n", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str()); break;
    case HTTP_UPDATE_NO_UPDATES: Serial.println("HTTP_UPDATE_NO_UPDATES"); break;
    case HTTP_UPDATE_OK: Serial.println("HTTP_UPDATE_OK"); break;
  }
}
void update_started() {
  Serial.println("CALLBACK:  HTTP update process started");
}
void update_finished() {
  Serial.println("CALLBACK:  HTTP update process finished");
}
void update_progress(int cur, int total) {
  Serial.printf("CALLBACK:  HTTP update process at %d of %d bytes...\n", cur, total);
}
void update_error(int err) {
  LED_Error();
  Serial.printf("CALLBACK:  HTTP update fatal error code %d\n", err);
}


void debug(int msg) {
  if (SYSDebug == 0) { return; }
  Serial.print("[DEBUG]");
  Serial.println(msg);
}
void debug(float msg) {
  if (SYSDebug == 0) { return; }
  Serial.print("[DEBUG]");
  Serial.println(msg);
}
void debug(String msg) {
  if (SYSDebug == 0) { return; }
  Serial.print("[DEBUG]");
  Serial.println(msg);
}



bool TCPing(String ip, int port) {
  if (tcping.connect(ip, port)) {
    debug("TCPing OK");
    tcping.stop();
    return true;
  } else {
    debug("TCPing NK");
    return false;
  }
}


void IP2int(String IP, uint8_t IPint[4]) {
  uint8_t startIndex = 0;
  uint8_t endIndex = 0;
  for (uint8_t i = 0; i < 4; i++) {
    endIndex = IP.indexOf('.', startIndex);
    if (endIndex == -1) {
      endIndex = IP.length();
    }
    String tmp = IP.substring(startIndex, endIndex);
    IPint[i] = tmp.toInt();
    startIndex = endIndex + 1;
  }
}


String extractTagValue(const String &data, const String &tagStart, const String &tagEnd) {
  int startIdx = data.indexOf(tagStart);
  int endIdx = data.indexOf(tagEnd);

  if (startIdx != -1 && endIdx != -1 && endIdx > startIdx) {
    startIdx += tagStart.length();
    return data.substring(startIdx, endIdx);
  }
  return "";
}


IPAddress stringToIPAddress(const String &str) {
  int parts[4];
  IPAddress ip;
  if (sscanf(str.c_str(), "%d.%d.%d.%d", &parts[0], &parts[1], &parts[2], &parts[3]) == 4) {
    for (int i = 0; i < 4; i++) {
      if (parts[i] < 0 || parts[i] > 255) {
        return IPAddress();
      }
    }
    ip = IPAddress(parts[0], parts[1], parts[2], parts[3]);
    return ip;
  }
  return IPAddress();
}
