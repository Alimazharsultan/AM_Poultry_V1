void getdatafromserial() {
  Serial.println("You can write a command right now: ");
  if (Serial.available())
  {
    cmd = Serial.readString();
    cmd.trim();
    Serial.println(cmd);
    
    if (cmd == "debug")
    {
      debug_flag = 1;
    }
    else if (cmd == "debugoff")
    {
      debug_flag = 0;
    }

    else if (cmd == "time")
    {
      rtc.adjust(DateTime(__DATE__, __TIME__));
      delay(3000);
    }
    else if (cmd == "help" )
    {
      Serial.println("Enter keyword 'time' to set the time of rtc. \n");
      Serial.println("Enter keyword 'add' to enroll a new employee. \n");
      Serial.println("Enter keyword 'delete' to delete an enrolled employee. \n");
      Serial.println("Enter keyword 'debug' to get the serial print from various positions for debbuging. \n");
      Serial.println("Enter keyword 'debugoff' to end the serial data from esp32 for debugging. \n");
    }
    else if (cmd == "time" )
    {
      //  It is the function to adjust the time and date of rtc when connected to PC
      rtc.adjust(DateTime(__DATE__, __TIME__));
      delay(3000);
    }
    else if (cmd == "restart")
    {
      ESP.restart();
    }
  }
}
