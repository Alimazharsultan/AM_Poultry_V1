void handleHzSSID()
{
  Serial.println("Handle HzSSID is calling");
  EEPROM.write(306, 1);
  EEPROM.commit();
  master_reset();
  Serial.println(u_HzSSID);
  Serial.println("recieved Wifi change name");
  int sizeOfName = strlen(u_HzSSID.c_str());
  Serial.print("Size of name is ");
  Serial.println(sizeOfName);
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
  EEPROM.write(307, count);
  for (int i = 0 ; i < (count); i++)
  {
    EEPROM.write(i + 150, getName1[i]);
    EEPROM.commit();
    delay(100);
    Serial.print("Saving  ");
    Serial.println(getName1[i]);
  }
  Serial.println("new name saved in eeprom");
  delay(1000);
  //server.send(200, "text/html", u_HzSSID);
  //delay(3000);
  ESP.restart();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void handleHzPassword()
{
  EEPROM.write(308, 1);
  EEPROM.commit();
  Serial.print("recieved new password for Hz which is ");
  Serial.println(u_HzSSID);
  int sizeOfPassword = strlen(u_HzSSID.c_str());
  Serial.println(sizeOfPassword);
  char getHzPassword1[sizeOfPassword];
  int count = 1;
  u_HzSSID.toCharArray(getHzPassword1, sizeOfPassword);
  for (int i = 0; i < sizeOfPassword; i++)
  {
    if (getHzPassword1[i] != '\0')
    {
      count++;
    }
  }
  EEPROM.write(309, count);
  for (int i = 0 ; i < (count); i++)
  {
    EEPROM.write((i + 200), getHzPassword1[i]);
    EEPROM.commit();
    delay(100);
    Serial.print("Saving  ");
    Serial.println(getHzPassword1[i]);
  }
  EEPROM.commit();
  delay(1000);
  Serial.println("new name saved in eeprom");
  ESP.restart();
}
