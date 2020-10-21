void boot()
{
  //-----------------------ID------------------------------
  //-------------------------------------------------------
  master_reset();
  int checkForID = EEPROM.read(300);
  if (checkForID == 1)  //If true then Go to user define
  {
    int size1 = EEPROM.read(301);
    char a;
    u_ID = "";
    for (int i = 0 ; i < (size1); i++)
    {
      a = EEPROM.read(i);
      u_ID += a;
    }

    ID = u_ID;
  }
  else
  {
    default_credential();
    ID = d_ID;
  }
  ///////////////////////////////////////////
  ///////////////////////////////////////////
  ///////////////////////////////////////////
  ///////////////////////////////////////////
  int checkForInternetWifiSSID = EEPROM.read(302);
  if (checkForInternetWifiSSID == 1)  //If true then Go to user define
  {
    int size1 = EEPROM.read(303);
    char a;
    u_internetWifiSSID = "";
    for (int i = 0 ; i < (size1); i++)
    {
      a = EEPROM.read(i + 50);
      u_internetWifiSSID += a;
    }

    internetWifiSSID = u_internetWifiSSID;
  }
  else
  {
    default_credential();
    internetWifiSSID = d_internetWifiSSID;
  }

  //--------------------------------------------------------------------------------------------
  //--------------------------------------------------------------------------------------------
  int checkForInternetWifiPassword = EEPROM.read(304);
  if (checkForInternetWifiPassword == 1)    //If true then Go to user define
  {
    int size1 = EEPROM.read(305);
    char a;
    u_internetWifiPassword = "";
    for (int i = 0 ; i < (size1); i++)
    {
      a = EEPROM.read(i + 100);
      Serial.print("Getting pasword   ");
      Serial.println(a);
      u_internetWifiPassword += a;
    }
    Serial.print("u_wifipass  ");
    Serial.println(u_internetWifiPassword);
    internetWifiPassword = u_internetWifiPassword;
  }
  else
  {
    default_credential();
    internetWifiPassword = d_internetWifiPassword;
  }
  ///////////////////////////////////////////
  ///////////////////////////////////////////
  ///////////////////////////////////////////
  ///////////////////////////////////////////
  master_reset();
  int checkForHzSSID = EEPROM.read(306);
  if (checkForHzSSID == 1)  //If true then Go to user define
  {
    int size1 = EEPROM.read(307);
    char a;
    u_HzSSID = "";
    for (int i = 0 ; i < (size1); i++)
    {
      a = EEPROM.read(i + 150);
      u_HzSSID += a;
    }

    HzSSID = u_HzSSID;
  }
  else
  {
    default_credential();
    HzSSID = d_HzSSID;
  }

  //const char *ss = ssid1.c_str();
  //const char *pp = password1.c_str();


  //--------------------------------------------------------------------------------------------
  //--------------------------------------------------------------------------------------------
  int checkForHzPassword = EEPROM.read(308);
  if (checkForHzPassword == 1)    //If true then Go to user define
  {
    int size1 = EEPROM.read(309);
    char a;
    u_HzPassword = "";
    for (int i = 0 ; i < (size1); i++)
    {
      a = EEPROM.read(i + 200);
      Serial.print("Getting pasword   ");
      Serial.println(a);
      u_HzPassword += a;
    }
    Serial.print("u_wifipass  ");
    Serial.println(u_HzPassword);
    HzPassword = u_HzPassword;
  }
  else
  {
    default_credential();
    HzPassword = d_HzPassword;
  }
}
