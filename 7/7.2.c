int LED = 12; 
int MQ2pin = A0;

void setup() { 
  Serial.begin(9600); 
}

void loop() {
  float sensorValue; 
  sensorValue = analogRead(MQ2pin); // read analog input pin 0
  
  if(sensorValue >= 10){ 
    digitalWrite(LED,HIGH); 

    Serial.println("\nSensor Value: "); 
    Serial.print(sensorValue);
    Serial.println("\nDANGER\n"); 
  }
  else{
    digitalWrite(LED,LOW); 
    Serial.println("\nSensor Value: "); 
    Serial.print(sensorValue);

  }
  delay(1000); 
} 

float getsensorValue(int pin){ 
  return (analogRead(pin));
}
