#include<LM35.h>
#include<DFRobot_RGBLCD1602.h>

#define motorPin 13
#define pirPin 3

LM35 temp_sense(A0); 
DFRobot_RGBLCD1602 lcd(0x60, 16, 2);

void updateLCD(int temp){

    lcd.clear();
    delay(500);
    lcd.setCursor(1,0);
    lcd.print("Welcome!!");
    lcd.setCursor(1, 1);
    lcd.print("Temprature: " + String(temp));
    delay(2000);
    lcd.clear();
    

}

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin,OUTPUT);
  pinMode(pirPin, INPUT);

  lcd.init();
  lcd.clear();
  
}

void loop() {
  // put your main code here, to run repeatedly:

  int temp = temp_sense.cel();
  int isPresent = digitalRead(pirPin);

  if(isPresent && temp>20){

    digitalWrite(motorPin,HIGH);
    updateLCD(temp);
    
  }
  else if( isPresent && temp < 20){

    digitalWrite(motorPin, LOW);
    updateLCD(temp);

  }
  else{

    digitalWrite(motorPin,LOW);

    lcd.clear();
    delay(500);
    lcd.setCursor(1,0);
    lcd.print("Nobody is here");
    delay(500);
  }
}
