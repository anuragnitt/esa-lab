int LED = 12; 
int gas = A0;
int tmppin= A2;
int piezo = 13;

void setup() { 
  Serial.begin(9600); 
  pinMode(LED, OUTPUT);
  pinMode(piezo, OUTPUT);
  pinMode(gas,INPUT);
  pinMode(tmppin,INPUT);
  
}

void loop() {
  float sensorValue, tempSensor; 
  sensorValue = analogRead(gas); // read analog input pin 0
  
  tempSensor= analogRead(tmppin);
  
  bool smoke= sensorValue >= 300;
  bool temp= tempSensor >100;
  
  if(smoke&&temp){ 
    digitalWrite(LED,HIGH); 
    digitalWrite(piezo, HIGH);
    
    Serial.println("\nSmoke Sensor Value: "); 
    Serial.print(sensorValue);
    Serial.println("\nTemp Sensor Value: ");
    Serial.print(tempSensor);
    Serial.println(" \nDANGER\n"); 
  }
  else{
    digitalWrite(LED,LOW);
    digitalWrite(piezo, LOW);
    Serial.println("Smoke Sensor Value: "); 
    Serial.print(sensorValue);
    Serial.println("\nTemp Sensor Value: "); 
    Serial.print(tempSensor);
  }
  delay(1000); 
} 

float getsensorValue(int pin){ 
  return (analogRead(pin));
}
