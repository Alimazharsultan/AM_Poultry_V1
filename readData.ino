void readData(){
  
  Serial.println("handling readData function");
  readDataa.concat(HzSSID);
  readDataa.concat(',');
  readDataa.concat(HzPassword);
  readDataa.concat(',');
  readDataa.concat(ID);
  Serial.print("readData string is ");
  readDataa.concat(',');
  readDataa.concat(internetWifiSSID);
  readDataa.concat(',');
  readDataa.concat(internetWifiPassword);
  Serial.println(readDataa);
  server.send(200, "text", readDataa);
  delay(2000);
  readDataa = "";
}
