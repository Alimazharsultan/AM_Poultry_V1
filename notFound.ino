
void handleNotFound() {
  Serial.println("handle not found is calling");
  findData();
  if ( parameter == "HzSSID") {
    handleHzSSID();
  }
  else if (parameter == "HzPassword") {
    handleHzPassword();
  }
  else if(parameter == "internetSSID"){
    handleinternetWifiSSID();
  }
  else if(parameter == "internetPassword"){
    handleinternetWifiPassword();
  }
  else if (parameter == "readInfo")
  {
    readData();
  }
    Serial.println("Mismatched....");
}
