void readFile(fs::FS &fs, const char * path){
  char c;
  message = "";
  if (debug_flag == 1){
  Serial.println("In readFile function...");
    Serial.printf("Reading file: %s\n", path);
  }
    File file = fs.open(path);
    if(!file){
        if (debug_flag == 1){
        Serial.println("Failed to open file for reading");
        }
        return;
    }

    if (debug_flag == 1){
    Serial.print("Read from file: ");
    }
    while(file.available()){
        c = file.read();
        if(c == '\n'){
          if (debug_flag == 1){
          Serial.print(message);
          }
          update_web();
          message = "";
          //timerWrite(timer, 0);
          delay(500);
        }else{
          message = message + c;
          //timerWrite(timer, 0);
        }
    }
    file.close();
    
    deleteFile(SD, "/Remaining.txt");
    if (debug_flag == 1){
    Serial.println("exiting readFile function...");
    }
}
