#include <WiFi.h>
#include <EEPROM.h>
#include <WiFiClient.h>
#include <WiFiMulti.h>
#include <mDNS.h>
#include <WebServer.h>
#include <SPI.h>
#include <Wire.h>
#include "RTClib.h"
#include "FS.h" 
#include <SD.h>
#include <HardwareSerial.h>
#include <Arduino.h>
#include <TM1637Display.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "DHTesp.h"
#include "Ticker.h"
#ifndef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP32 ONLY!)
#error Select ESP32 board.
#endif

DHTesp dht;

void tempTask(void *pvParameters);
bool getTemperature();
void triggerGetTemp();
//3330320889719
/** Task handle for the light value read task */
TaskHandle_t tempTaskHandle = NULL;
/** Ticker for temperature reading */
Ticker tempTicker;
/** Comfort profile */
ComfortState cf;
/** Flag if task should run */
bool tasksEnabled = false;
/** Pin number for DHT11 data pin */
int dhtPin = 15;

String d_HzPassword;
String d_HzSSID;
String d_internetWifiPassword;
String d_internetWifiSSID;
String d_ID;

String HzSSID;
String HzPassword;
String internetWifiSSID;
String internetWifiPassword;
String ID;

String u_HzPassword;
String u_HzSSID;
String u_internetWifiPassword;
String u_internetWifiSSID;
String u_ID, message1, parameter, secret, readDataa = "", lastName, fulName;

WiFiUDP ntpUDP;

// You can specify the time server pool and the offset (in seconds, can be
// changed later with setTimeOffset() ). Additionaly you can specify the
// update interval (in milliseconds, can be changed using setUpdateInterval() ).
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 18000, 60000);

WebServer server(80);
int addressOfName = 0;
int addressOfPassword = 100;

String webpage, webPageSetting;
const int master_reset_button = 4; //D5

WiFiClient client;

HardwareSerial mySerial(2);
//Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);// creating an object finger
RTC_DS3231 rtc;

const char* host = "t.khirds.com";
const int httpPort = 80;

// Module connection pins (Digital Pins)
#define CLK 33
#define DIO 32

#define RL1 13
#define RL2 12
#define RL3 14
#define RL4 27

#define TEST_DELAY   2000


const uint8_t SEG_DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
};

const uint8_t SEG_PASS[] = {
  SEG_A | SEG_B | SEG_E | SEG_F | SEG_G,          // P
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,  // A
  SEG_A | SEG_C | SEG_D | SEG_F | SEG_G,          // S
  SEG_A | SEG_C | SEG_D | SEG_F | SEG_G           // S
};

const uint8_t SEG_FAIL[] = {
  SEG_A | SEG_E | SEG_F | SEG_G,                  // F
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,  // A
  SEG_B | SEG_C,                                  // I
  SEG_D | SEG_E | SEG_F                           // L
};

const uint8_t SEG_F001[] = {
  SEG_A | SEG_E | SEG_F | SEG_G,                  // F
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
  SEG_B | SEG_C,                                  // 1

};
const uint8_t SEG_F002[] = {
  SEG_A | SEG_E | SEG_F | SEG_G,                  // F
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
  SEG_A | SEG_B | SEG_D | SEG_E | SEG_G,          // 2

};

const uint8_t SEG_F003[] = {
  SEG_A | SEG_E | SEG_F | SEG_G,                  // F
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_G,          // 3

};

const uint8_t SEG_F004[] = {
  SEG_A | SEG_E | SEG_F | SEG_G,                  // F
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
  SEG_B | SEG_C | SEG_F | SEG_G,                  // 4

};

const uint8_t SEG_F005[] = {
  SEG_A | SEG_E | SEG_F | SEG_G,                  // F
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
  SEG_A | SEG_C | SEG_D | SEG_F | SEG_G ,         // 5

};

const uint8_t SEG_PULL[] = {
  SEG_A | SEG_B | SEG_E | SEG_F | SEG_F | SEG_G,  // P
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,          // U
  SEG_D | SEG_E | SEG_F,                          // L
  SEG_D | SEG_E | SEG_F,                          // L

};
const uint8_t SEG_UPLD[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,          // U
  SEG_A | SEG_B | SEG_E | SEG_F | SEG_F | SEG_G,  // P
  SEG_D | SEG_E | SEG_F,                          // L
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,                         // L

};

const uint8_t SEG_PUSH[] = {
  SEG_A | SEG_B | SEG_E | SEG_F | SEG_F | SEG_G,  // P
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,          // U
  SEG_A | SEG_C | SEG_D | SEG_F | SEG_G ,         // S
  SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,          // H

};

// Create variable:
int temperature_celsius;
int temperature_fahrenheit;
// Create degree Celsius symbol:
const uint8_t celsius[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_D | SEG_E | SEG_F   // C
};
// Create degree Fahrenheit symbol:
const uint8_t fahrenheit[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_B | SEG_F | SEG_G   // F
};


TM1637Display display(CLK, DIO);

// Variables to be used
String Time = "";         //Time from rtc in Time_day function
String cmd = "";          //command from serial port to add or delete the ids(Commands are "add" and "delete")
uint8_t id = 0;           //id is the employee id for enroll or delete
uint8_t A_ID = 0;           //ID is the employee id for enroll if it has successfully enrolled
String data = "1";        //data contains the employee id that has been found
String message = "";      //message contains the string that has been sent to firebase
uint8_t TotalAdded = 100;   //number of total added employee ids to add the next id
bool debug_flag = 0;      //debug_flag is used to monitor the serial communication
bool sendEmployeeInfoFlag = 0; //if flag = 1 then send the employeedata log to server
String formattedDate;
String dayStamp;
String timeStamp, timeToSent = "";

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
unsigned showtimei = 0;

void setup(void) {
  display.setBrightness(0x0f);
  display.setSegments(SEG_DONE);
  Serial.begin(115200);
  Serial.println();
  Serial.println("HAZIR.S-Poultry-Mangnagment-V3 ");
  EEPROM.begin(512);
  pinMode(master_reset_button, INPUT_PULLUP);
  pinMode(RL1, OUTPUT);
  pinMode(RL2, OUTPUT);
  pinMode(RL3, OUTPUT);
  pinMode(RL4, OUTPUT);

  boot();
  const char *ss = HzSSID.c_str();
  const char *pp = HzPassword.c_str();
  const char *ssid = internetWifiSSID.c_str() ;
  const char *password = internetWifiPassword.c_str() ;
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP(ss, pp);
  delay(1000);
  WiFi.begin(ssid, password);
  delay(1000);
  Serial.println();
  Serial.print("Hz SSID  "); Serial.println(ss);
  Serial.print("Hz password  "); Serial.println(pp);
  Serial.print("Device ID  "); Serial.println(ID);
  Serial.print("internet ssid  "); Serial.println(ssid);
  Serial.print("intenet password  "); Serial.println(password);
  server.on("/readData", HTTP_POST, readData);
  server.onNotFound(handleNotFound);        // When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"
  server.begin();                           // Actually start the server
  Serial.println("Server started");
  Wire.begin();
  //SD Card Initialization
  if (!SD.begin()) {
    Serial.println("Card Mount Failed");
    display.setSegments(SEG_F004);
    delay(1000);
  }
  
  wifi_status();
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    display.setSegments(SEG_F002);
    delay(1000);
  }
  delay(1000);
  timeClient.begin();
  if (WiFi.status() == WL_CONNECTED) {
    timeClient.update();
    date_time();
  }
  else
    Serial.println("Wifi not availeble");
}

void loop(void) {
  showtimei++;
  server.handleClient();                    // Listen for HTTP requests from clients
  master_reset();
  getdatafromserial();
  //  getFingerprintIDez();
  //  if (sendEmployeeInfoFlag == 1) {
  //    sendEmployeeInfo(SD, "/EmployeeData.txt");
  //  }
  showTime();
  getTemperature() ;
  delay(5000);
  //timeClient.update();
  Serial.print("NTP time: ");
  Serial.println(timeClient.getFormattedTime());
  Time_day();
  delay(5000);
  //    Serial.print(now.hour());Serial.print(":");Serial.println(now.minute());
  delay(500);
}
