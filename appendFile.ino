void appendFile(fs::FS &fs, const char * path) {
  if (debug_flag == 1) {
    Serial.println("In appendedFile function");
  }
  //SD Card Initialization
  if (!SD.begin()) {
    display.setSegments(SEG_F004);
    delay(1000);
  }
  if (debug_flag == 1) {
    Serial.printf("Appending to file: %s\n", path);
  }

  File file = fs.open(path, FILE_APPEND);
  if (!file) {
    if (debug_flag == 1) {
      Serial.println("Failed to open file for appending");
    }
    return;
  }
  //write your message to appened at the place of "message"
  if (file.println(message)) {
    if (debug_flag == 1) {
      Serial.println("Message appended");
    }
  } else {
    if (debug_flag == 1) {
      Serial.println("Append failed");
    }
  }
  file.close();
}
