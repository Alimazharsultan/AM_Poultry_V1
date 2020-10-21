
void handleID()
{
  EEPROM.write(300, 1);
  EEPROM.commit();
  master_reset();
  String getID = server.arg("changeID");
  getID.trim();
  Serial.println("New ID recieved");
  Serial.println(getID);
  int sizeOfName = sizeof(getID);
  EEPROM.commit();
  char getID1[sizeOfName];
  int count = 1;
  getID.toCharArray(getID1, sizeOfName);
  for (int i = 0; i < sizeOfName; i++)
  {
    if (getID1[i] != '\0')
    {
      count++;
    }
  }
  EEPROM.write(301,count);
  for (int i = 0 ; i < (count); i++)
  {
    EEPROM.write(i, getID1[i]);
    EEPROM.commit();
    delay(100);
    Serial.print("Saving  ");
    Serial.println(getID1[i]);
  }
  Serial.println("new ID saved in EEPROM");
  delay(1000);
  ESP.restart();
}
