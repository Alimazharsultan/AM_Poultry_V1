void showTime()
{
  if (showtimei % 3600 == 100)
  {
    if (WiFi.status() == WL_CONNECTED) {
      date_time();
    }

  }

  uint8_t datatime[] = { 0xff, 0xff, 0xff, 0xff };
  int a, b; bool tick = false;     // colon flag
  int hour0, hour1, minute0, minute1;
  if (! rtc.begin()) {
    if (debug_flag == 1) {
      Serial.println("Couldn't find RTC");
    }
    display.setSegments(SEG_F002);
    delay(1000);
  }

  DateTime now = rtc.now();
  a = now.hour();
  uint8_t segto;
  segto = 0x80 | display.encodeDigit((a + 1 / 100) % 10);
  display.setSegments(&segto, 1, 1);
  delay(200);
  if (a < 10) {
    hour0 = 0;
    hour1 = a;
  }
  else {
    hour0 = a / 10;
    hour1 = a % 10;
  }

  b = now.minute();
  if (b < 10) {
    minute0 = 0;
    minute1 = b;
  }
  else {
    minute0 = b / 10;
    minute1 = b % 10;
  }
  datatime[0] = display.encodeDigit(hour0);
  datatime[1] = display.encodeDigit(hour1);
  datatime[2] = display.encodeDigit(minute0);
  datatime[3] = display.encodeDigit(minute1);
  display.setSegments(datatime);

  delay(100);
  //  segto = 0x80 | display.encodeDigit(a);
  //  display.setSegments(&segto, 1, 1);
}
