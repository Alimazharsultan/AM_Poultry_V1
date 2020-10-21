void handleinternetWifiSSID()
{
  EEPROM.write(302, 1);
  EEPROM.commit();
  master_reset();
  Serial.print("Recieved new internet Wifi SSID which is ");
  Serial.println(u_HzSSID);
  int sizeOfName = strlen(u_HzSSID.c_str());
  EEPROM.commit();
  char getName1[sizeOfName];
  int count = 1;
  u_HzSSID.toCharArray(getName1, sizeOfName);
  for (int i = 0; i < sizeOfName; i++)
  {
    if (getName1[i] != '\0')
    {
      count++;
    }
  }
  EEPROM.write(303,count);
  for (int i = 0 ; i < (count); i++)
  {
    EEPROM.write((i+50), getName1[i]);
    EEPROM.commit();
    delay(100);
    Serial.print("Saving  ");
    Serial.println(getName1[i]);
  }
  Serial.println("new internet wifi ssid saved in eeprom");
  delay(1000);
  ESP.restart();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

void handleinternetWifiPassword()
{
  EEPROM.write(304, 1);
  EEPROM.commit();
  Serial.print("New password for internet Wifi is recieved which is ");
  Serial.println(u_HzSSID);
  int sizeOfPassword = strlen(u_HzSSID.c_str());
  Serial.println(sizeOfPassword);
  char getPassword1[sizeOfPassword];
  int count = 1;
  u_HzSSID.toCharArray(getPassword1, sizeOfPassword);
  for (int i = 0; i < sizeOfPassword; i++)
  {
    if (getPassword1[i] != '\0')
    {
      count++;
    }
  }
  EEPROM.write(305,count);
  for (int i = 0 ; i < (count); i++)
  {
    EEPROM.write((i+100), getPassword1[i]);
    EEPROM.commit();
    delay(100);
    Serial.print("Saving  ");
    Serial.println(getPassword1[i]);
  }
  EEPROM.commit();
  delay(1000);
  Serial.println("new name saved in eeprom");
  ESP.restart();
}
