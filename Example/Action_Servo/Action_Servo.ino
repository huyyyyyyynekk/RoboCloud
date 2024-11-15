//Khai báo thư viện cần thiết.
//...................

/////
int number = 0;
bool check = true;
void loop() {
  if (Serial.available()) {
    String inputString = Serial.readStringUntil('\n'); 
    number = inputString.toInt(); 
    Serial.println(number); 
  }
  if (number == 1){
    Action_Servo("Funny");
  }
  else if (number == 2){
    Action_Servo("Happy");
  }
  else if (number == 3){
    Action_Servo("Cute");
  }
  else if (number == 4){
    Action_Servo("Shy");
  }
  else if (number == 5){
    Action_Servo("Guilty");
  }
  else if (number == 6){
    Action_Servo("Considering");
  }
  else if (number == 7){
    Action_Servo("Flattering");
  }
  else if (number == 8){
    Action_Servo("Presenting");
  }
  else if (number == 9 && check == true){
    Serial.print("Left :");
    Serial.println(Left_Hand_Pos);
    Serial.print("Right :");
    Serial.println(Right_Hand_Pos);
    Serial.print("Head :");
    Serial.println(Head_Pos);
    Serial.print("Plinth :");
    Serial.println(Plinth_Pos);
    check = false;
  }
  else if (number == 10 && check == false){
    check = true;
    Serial.println("Stop!");
  }
  else if (number == 11){
    Action_Servo("Demonstrate");
  }
  else if (number == 12){
    Action_Servo("Thinking");
  }
  else if (number == 13){
    Action_Servo("Woo");
  }
  else if (number == 14){
    Action_Servo("Balance");
  }
}