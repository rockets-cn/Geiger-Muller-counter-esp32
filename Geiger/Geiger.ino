// include library, include base class, make path known
#include <GxEPD.h>
#include "SPI.h"

//  由于屏幕有多个版本，如下载程序后出现花屏请将下面4个头文件都测试一遍！
#include <GxDEPG0213BN/GxDEPG0213BN.h>
//#include <GxGDE0213B1/GxGDE0213B1.h>      // 2.13" b/w
//#include <GxGDEH0213B72/GxGDEH0213B72.h>  // 2.13" b/w new panel
//#include <GxGDEH0213B73/GxGDEH0213B73.h>  // 2.13" b/w newer panel

int bmpWidth = 232, bmpHeight = 52;
//width:150,height:39

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>


#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#define SPI_MOSI 23
#define SPI_MISO -1
#define SPI_CLK 18

#define ELINK_SS 5
#define ELINK_BUSY 4
#define ELINK_RESET 16
#define ELINK_DC 17

#define SDCARD_SS 13
#define SDCARD_CLK 14
#define SDCARD_MOSI 15
#define SDCARD_MISO 2

#define BUTTON_PIN 39

#define GEIGER_PIN 33

GxIO_Class io(SPI, /*CS=5*/ ELINK_SS, /*DC=*/ ELINK_DC, /*RST=*/ ELINK_RESET);
GxEPD_Class display(io, /*RST=*/ ELINK_RESET, /*BUSY=*/ ELINK_BUSY);

SPIClass sdSPI(VSPI);


const char *Website = "www.dfrobot.com";
bool sdOK = false;
int startX = 9, startY = 20;
int Count = 0;
int Total = 0;
bool Changed;

void callBack(void)
{
  int level = digitalRead(GEIGER_PIN); 
  // Serial.printf("%d\n", level);      

  if(level == 0) {
    Count++;
    Changed = true;
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");

  pinMode(GEIGER_PIN, INPUT);    //GPIO_13,输出模式
  attachInterrupt(GEIGER_PIN, callBack, CHANGE);  //当电平发生变化时，触发中断

  SPI.begin(SPI_CLK, SPI_MISO, SPI_MOSI, ELINK_SS);
  display.init(); // enable diagnostic output on Serial

  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.setFont(&FreeMonoBold12pt7b);
  display.update();

  // goto sleep
  // esp_sleep_enable_ext0_wakeup((gpio_num_t)GEIGER_PIN, LOW);

  // esp_deep_sleep_start();
}

void loop()
{
  if(Changed)
  {    
    char buf[50];

    Total += Count;

    display.fillScreen(GxEPD_WHITE);
    //display.fillRect(0, 95, 200, 10, GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);

    sprintf(buf, "R %.2f uSv/h", Count * 2 / 153.8);  
    display.setCursor(20, 70);
    display.println(buf);

    sprintf(buf, "C %d", Total);  
    display.setCursor(20, 90);
    display.println(buf);

    //display.updateWindow(0, 61,  250,  61, false);
    display.update();

    Changed = false;
    Count = 0;
  }

  delay(30000);  
}