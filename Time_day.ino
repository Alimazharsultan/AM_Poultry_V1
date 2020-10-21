void Time_day()
{
  if (! rtc.begin()) {
    if (debug_flag == 1) {
      Serial.println("Couldn't find RTC");
    }
    display.setSegments(SEG_F002);
    delay(1000);
  }

  DateTime now = rtc.now();
  Time = String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second()) + "," + String(now.day()) + ":" + String(now.month()) + ":" + String(now.year());
  Serial.print("RTC time:- ");
  Serial.print(now.hour()); Serial.print(":"); Serial.println(now.minute());
// if ((now.hour() == 15) && (now.minute() == 50))
//  if (((now.hour() == 16) && (now.minute() == 14)) || ((now.hour() == 15) && (now.minute() == 55)) || ((now.hour() == 17) && (now.minute() == 55)) || ((now.hour() == 19) && (now.minute() == 55)) || ((now.hour() == 21) && (now.minute() == 55))|| ((now.hour() == 23) && (now.minute() == 55)) || ((now.hour() == 1) && (now.minute() == 55)) || ((now.hour() == 3) && (now.minute() == 55)) || ((now.hour() == 5) && (now.minute() == 55)) || ((now.hour() == 7) && (now.minute() == 55))|| ((now.hour() == 9) && (now.minute() == 55)) || ((now.hour() == 11) && (now.minute() == 55)) || ((now.hour() == 13) && (now.minute() == 55)) )
  
 if ( ((now.hour() == 23) && (now.minute() == 14)) ||((now.hour() == 22) && (now.minute() == 14)) ||((now.hour() == 21) && (now.minute() == 14)) ||((now.hour() == 20) && (now.minute() == 14)) ||((now.hour() == 19) && (now.minute() == 14)) ||((now.hour() == 18) && (now.minute() == 14)) || ((now.hour() == 17) && (now.minute() == 14)) || ((now.hour() == 16) && (now.minute() == 14))||((now.hour() == 16) && (now.minute() == 14)) || ((now.hour() == 15) && (now.minute() == 55)) || ((now.hour() == 14) && (now.minute() == 55)) || ((now.hour() == 13) && (now.minute() == 55)) || ((now.hour() == 12) && (now.minute() == 55))|| ((now.hour() == 11) && (now.minute() == 55)) || ((now.hour() == 10) && (now.minute() == 55)) || ((now.hour() == 9) && (now.minute() == 55)) || ((now.hour() == 8) && (now.minute() == 55)) || ((now.hour() == 7) && (now.minute() == 55))|| ((now.hour() == 6) && (now.minute() == 55)) || ((now.hour() == 5) && (now.minute() == 55)) || ((now.hour() == 4) && (now.minute() == 55)) || ((now.hour() == 3) && (now.minute() == 55)) || ((now.hour() == 2) && (now.minute() == 55)) || ((now.hour() == 1) && (now.minute() == 55)) )

  {
    Serial.println("done high");
    display.setSegments(SEG_DONE);
    delay(5000);
    digitalWrite(RL1, HIGH); 
    digitalWrite(RL2, HIGH); 
    digitalWrite(RL3, HIGH); 
    digitalWrite(RL4, HIGH); 
   
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



  if (debug_flag == 1) {
    Serial.print("Time : ");
    Serial.println(Time);
  }
}
