void initServo() {
  servohori.setPeriodHertz(50);
  servohori.attach(servoh, 1000, 2000);
  servohoriStruct.readServo = 0;
  servohoriStruct.highLimit = 160;
  servohoriStruct.lowLimit = 60;
  servohori.write(60);
  servoverti.setPeriodHertz(50);
  servoverti.attach(servol, 1000, 2000);
  servovertiStruct.readServo = 0;
  servovertiStruct.highLimit = 160;
  servovertiStruct.lowLimit = 60;
  servoverti.write(60);
}
void controlServo() {
  servohoriStruct.readServo = servohori.read();
  servovertiStruct.readServo = servoverti.read();
  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);
  Serial.print(servohoriStruct.readServo);
  Serial.print(" ");
  Serial.print(servovertiStruct.readServo);
  Serial.print(" ");
  Serial.print(topl);
  Serial.print(" ");
  Serial.print(topr);
  Serial.print(" ");
  Serial.print(botl);
  Serial.print(" ");
  Serial.println(botr);
  int avgtop = (topl + topr) / 2 ; //average of top
  int avgbot = (botl + botr) / 2 ; //average of bottom
  int avgleft = (topl + botl) / 2 ; //average of left
  int avgright = (topr + botr) / 2 ; //average of right
  if (avgtop / 1000 == avgbot / 1000 && avgbot / 1000 == avgleft / 1000 && avgleft / 1000 == avgright / 1000)
  {
    servoverti.write(servovertiStruct.readServo);
  }
  else if (avgtop < avgbot)
  {
    Serial.println("test");
    servoverti.write(servovertiStruct.readServo + 5);
    if (servovertiStruct.readServo > servovertiStruct.highLimit)
    {
      servovertiStruct.readServo = servovertiStruct.highLimit;
    }
    delay(10);
  }
  else if (avgbot < avgtop)
  {
    servoverti.write(servovertiStruct.readServo - 5);
    if (servovertiStruct.readServo < servovertiStruct.lowLimit)
    {
      servovertiStruct.readServo = servovertiStruct.lowLimit;
    }
    delay(10);
  }
  else
  {
    servoverti.write(servovertiStruct.readServo);
  }
  if (avgtop / 1000 == avgbot / 1000 && avgbot / 1000 == avgleft / 1000 && avgleft / 1000 == avgright / 1000)
  {
    servoverti.write(servovertiStruct.readServo);
  }
  else if (avgleft > avgright)
  {
    servohori.write(servohoriStruct.readServo + 5);
    if (servohoriStruct.readServo > servohoriStruct.highLimit)
    {
      servohoriStruct.readServo = servohoriStruct.highLimit;
    }
    delay(10);
  }
  else if (avgright > avgleft)
  {
    servohori.write(servohoriStruct.readServo - 5);
    if (servohoriStruct.readServo < servohoriStruct.lowLimit)
    {
      servohoriStruct.readServo = servohoriStruct.lowLimit;
    }
    delay(10);
  }
  else
  {
    servohori.write(servohoriStruct.readServo);
  }
  delay(50);
}
