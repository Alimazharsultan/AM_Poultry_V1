void findData() {
  message1 = server.uri();
  Serial.print("Message recieved is ");
  message1.replace("/", "");
  Serial.println(message1);
  parameter = getStringPartByNr(message1, ':', 0);
  Serial.print("Recieved parameter is ");
  Serial.println(parameter);
  u_HzSSID = getStringPartByNr(message1, ':', 1);
  if (parameter == "addNew") {
    lastName = getStringPartByNr(message1, ' ', 1);
    fulName="";
    fulName.concat(u_HzSSID);
    fulName.concat(' ');
    fulName.concat(lastName);
    Serial.print("First name is ");
    Serial.println(u_HzSSID);
    Serial.print("second name is ");
    Serial.println(lastName);
    Serial.print("Full name is ");
    Serial.println(fulName);
  }
  Serial.print("Recieved u_HzSSID is ");
  Serial.println(u_HzSSID);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

String getStringPartByNr(String data, char separator, int index)
{
  // spliting a string and return the part nr index
  // split by separator

  int stringData = 0;        //variable to count data part nr
  String dataPart = "";      //variable to hole the return text

  for (int i = 0; i < data.length() + 1; i++) { //Walk through the text one letter at a time

    if (data[i] == separator) {
      //Count the number of times separator character appears in the text
      stringData++;

    } else if (stringData == index) {
      //get the text when separator is the rignt one
      dataPart.concat(data[i]);

    } else if (stringData > index) {
      //return text and stop if the next separator appears - to save CPU-time
      return dataPart;
      break;

    }

  }
  //return text if this is the last part
  return dataPart;
}
