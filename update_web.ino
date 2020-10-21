void update_web()
{
  if (debug_flag == 1){
  Serial.println("In update_web function...");
  }
 
  if (!client.connect(host, httpPort)) {
   if (debug_flag == 1){
    Serial.println("client is failed");
   }
    appendFile(SD, "/Remaining.txt");
    if (debug_flag == 1){
    Serial.println("Value saved to Remaining.txt");
    }
  }
  else{
  // We now create a URL for the request

    String url = "";
    url = "http://khirds.com/t/ks/controller/AtendanceC.php?v=addRec," + message;
    url.trim();
    if (debug_flag == 1){
    Serial.print("Requesting URL: ");
    Serial.println(url);
    }
    
  // This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        if (debug_flag == 1){
        Serial.println(">>> Client Timeout !");
        }
        client.stop();
        return;
      }
    }

  // Read all the lines of the reply from server and print them to Serial
    while (client.available()) {
      String line = client.readStringUntil('\r');
      if (debug_flag == 1){
      Serial.print(line);
      }
    }

    if (debug_flag == 1){
    Serial.println();
    Serial.println("closing connection");
    Serial.println("Exiting update_web function...");
    }
    }
}
