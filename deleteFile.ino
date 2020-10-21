void deleteFile(fs::FS &fs, const char * path){
  if (debug_flag == 1){
    Serial.printf("Deleting file: %s\n", path);
  }
    if(fs.remove(path)){
      if (debug_flag == 1){
        Serial.println("File deleted");
      }
    } else {
      if (debug_flag == 1){
        Serial.println("Delete failed");
      }
    }
}
