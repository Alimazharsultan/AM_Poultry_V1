void date_time() {
  delay(1000);
  // The formattedDate comes with the following format:
  // 2018-05-28T16:00:13Z
  // We need to extract date and time
  formattedDate = timeClient.getFormattedDate();
  int splitT = formattedDate.indexOf("T");
  dayStamp = formattedDate.substring(0, splitT);
  timeStamp = formattedDate.substring(splitT + 1, formattedDate.length() - 1);
  String year1 = getStringPartByNr(formattedDate, '-', 0);
  String month1 = getStringPartByNr(formattedDate, '-', 1);
  dayStamp = formattedDate.substring(0, splitT - 2);
  formattedDate.replace(dayStamp, "");
  String day1 = getStringPartByNr(formattedDate, 'T', 0);
  timeStamp.concat(':');
  String hr = getStringPartByNr(timeStamp, ':', 0);
  String mint = getStringPartByNr(timeStamp, ':', 1);
  String sec = getStringPartByNr(timeStamp, ':', 2);
  Serial.println("Adjusting new time");
  Serial.print(year1.toInt());
  Serial.print(month1.toInt());
  Serial.print(day1.toInt());
  Serial.print(hr.toInt());
  Serial.print(mint.toInt());
  Serial.println(sec.toInt());
  if (year1.toInt() !=1970){
  rtc.adjust(DateTime(year1.toInt(), month1.toInt(), day1.toInt(), hr.toInt(), mint.toInt(), sec.toInt()));
  }
//  display.setSegments(SEG_UPLD);
//  delay(1000);
}
