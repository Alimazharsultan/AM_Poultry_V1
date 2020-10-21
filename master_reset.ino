void master_reset()
{
  bool a = digitalRead(master_reset_button);
  if (!a)
  {
    delay(5000);
    a = digitalRead(master_reset_button);
    if (!a)
    {
      HzSSID = "Hazir";
      HzPassword = "hazir1234";
      ID = "001";
      EEPROM.write(300,0);
      EEPROM.commit();
      EEPROM.write(302,0);
      EEPROM.commit();
      EEPROM.write(304,0);
      EEPROM.commit();
      ESP.restart();
    }
  }
}
