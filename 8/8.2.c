
#include <LiquidCrystal.h>
#include <Keypad.h>

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {10,9,8,7}; //Rows 0 to 3
byte colPins[numCols]= {A0,A1,A2,A3}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int tilt = A4;

char buf[16]={0};
int cnt =0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(tilt, INPUT);
}


void loop() {
  int reading = analogRead(tilt);
  
  
  char keypressed = myKeypad.getKey();
  
  Serial.println(reading);
    
  if(reading>100){ 
    
    buf[cnt] = keypressed;
    if(keypressed != 0) cnt++;
    cnt%=16;
    buf[cnt]=0;
    lcd.clear();
    lcd.print(buf);
    
  }else{
    lcd.clear();
    lcd.print("IDLE");
  }
  
  delay(50);
}
