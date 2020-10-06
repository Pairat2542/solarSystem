float readVoltage() {
  //int comingData = analogRead(voltagePin) / 4.812;
  //return float((comingData % 100)) / 10;
  return analogRead(voltagePin) /193.94;
}
