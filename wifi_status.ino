void wifi_status()
{
  if (WiFi.status() != WL_CONNECTED)
  {
//WiFi.begin(ssid);

    if (WiFi.status() != WL_CONNECTED) {
      display.setSegments(SEG_F003);
      delay(1000);
    }
     //Serial.println(WiFi.localIP());
  }
  else {
    if (!client.connect(host, httpPort)) {
      //donothing its just a check
    }
    else{
    readFile(SD, "/Remaining.txt");
    if (debug_flag == 1){
    Serial.println("here 2");
    }
    }
  }
if (debug_flag == 1){
  Serial.print("localIP:");
  Serial.println(WiFi.localIP());
}
}
