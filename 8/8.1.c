#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int force = 0;
int red = 4;
int blue = 3;
int green = 2;
void setup()
{
  lcd.begin(16, 2); 
  pinMode(A0, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  force = analogRead(A0);
  Serial.println(force);
  lcd.clear();
  lcd.print(force);
  if(force<100){
   	digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(red, LOW);
  }else if(force < 300){
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(red, LOW);
  }else{
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(red, HIGH);
  }
  delay(1000); 
}
