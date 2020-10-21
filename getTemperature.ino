
/**
   getTemperature
   Reads temperature from DHT11 sensor
   @return bool
      true if temperature could be aquired
      false if aquisition failed
*/
bool getTemperature() {
  //  /  byte resultValue = 0;
  //  // Initialize temperature sensor
  dht.setup(dhtPin, DHTesp::DHT11);
  // Reading temperature for humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
  TempAndHumidity newValues = dht.getTempAndHumidity();
  // Check if any reads failed and exit early (to try again).
  if (dht.getStatus() != 0) {
    Serial.println("DHT11 error status: " + String(dht.getStatusString()));
    return false;
  }

  float heatIndex = dht.computeHeatIndex(newValues.temperature, newValues.humidity);
  float dewPoint = dht.computeDewPoint(newValues.temperature, newValues.humidity);
  float cr = dht.getComfortRatio(cf, newValues.temperature, newValues.humidity);

  String comfortStatus;
  switch (cf) {
    case Comfort_OK:
      comfortStatus = "Comfort_OK";
      break;
    case Comfort_TooHot:
      comfortStatus = "Comfort_TooHot";
      break;
    case Comfort_TooCold:
      comfortStatus = "Comfort_TooCold";
      break;
    case Comfort_TooDry:
      comfortStatus = "Comfort_TooDry";
      break;
    case Comfort_TooHumid:
      comfortStatus = "Comfort_TooHumid";
      break;
    case Comfort_HotAndHumid:
      comfortStatus = "Comfort_HotAndHumid";
      break;
    case Comfort_HotAndDry:
      comfortStatus = "Comfort_HotAndDry";
      break;
    case Comfort_ColdAndHumid:
      comfortStatus = "Comfort_ColdAndHumid";
      break;
    case Comfort_ColdAndDry:
      comfortStatus = "Comfort_ColdAndDry";
      break;
    default:
      comfortStatus = "Unknown:";
      break;
  };

  Serial.println(" T:" + String(newValues.temperature) + " H:" + String(newValues.humidity) + " I:" + String(heatIndex) + " D:" + String(dewPoint) + " " + comfortStatus);
  //  temperature_celsius = dht.readTemperature();
  //  temperature_fahrenheit = dht.readTemperature(true);
  //  // Print the temperature to the Serial Monitor:
  //  Serial.println(temperature_celsius);
  //  Serial.println(temperature_fahrenheit);
  //  // Show the temperature on the TM1637 display:
  display.showNumberDec(newValues.temperature, false, 2, 0);
  display.setSegments(celsius, 2, 2);
  delay(2000);
  display.showNumberDec(newValues.humidity, false, 2, 0);
  display.setSegments(fahrenheit, 2, 2);
  delay(2000);


  if (newValues.humidity > 80)

  {
    Serial.println("done high");
    display.setSegments(SEG_DONE);
    delay(5000);
    digitalWrite(RL1, HIGH); // sets the digital pin 13 on
    digitalWrite(RL2, HIGH); // sets the digital pin 13 on
    digitalWrite(RL3, HIGH); // sets the digital pin 13 on
    digitalWrite(RL4, HIGH); // sets the digital pin 13 on
    //delay(1000);            // waits for a second

    //delay(1000);            // waits for a second
    debug_flag = 0;
  }
  else
  {
    Serial.println("done low");
    display.setSegments(SEG_F001);
    delay(5000);
    digitalWrite(RL1, LOW); // sets the digital pin 13 on
    digitalWrite(RL2, LOW); // sets the digital pin 13 on
    digitalWrite(RL3, LOW); // sets the digital pin 13 on
    digitalWrite(RL4, LOW); // sets the digital pin 13 on
  }






  ///
  //  TempAndHumidity newValues = dht.getTempAndHumidity();
  //  datestring = String(newValues.temperature) + '-' + 'C';

  return true;
}

//  uint8_t datatime[] = { 0xff, 0xff, 0xff, 0xff };
//  int a, b; bool tick = false;     // colon flag
//  int hour0, hour1, minute0, minute1;
//  if (! rtc.begin()) {
//    if (debug_flag == 1) {
//      Serial.println("Couldn't find RTC");
//    }
//    display.setSegments(SEG_F002);
//    delay(1000);
//  }
//
//  DateTime now = rtc.now();
//  a = now.hour();
//  uint8_t segto;
//  segto = 0x80 | display.encodeDigit((a + 1 / 100) % 10);
//  display.setSegments(&segto, 1, 1);
//  delay(200);
//  if (a < 10) {
//    hour0 = 0;
//    hour1 = a;
//  }
//  else {
//    hour0 = a / 10;
//    hour1 = a % 10;
//  }
//
//  b = now.minute();
//  if (b < 10) {
//    minute0 = 0;
//    minute1 = b;
//  }
//  else {
//    minute0 = b / 10;
//    minute1 = b % 10;
//  }
//  datatime[0] = display.encodeDigit(hour0);
//  datatime[1] = display.encodeDigit(hour1);
//  datatime[2] = display.encodeDigit(minute0);
//  datatime[3] = display.encodeDigit(minute1);
//  display.setSegments(datatime);
//
//  delay(100);
//  //  segto = 0x80 | display.encodeDigit(a);
//  //  display.setSegments(&segto, 1, 1);
//}
