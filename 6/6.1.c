#define F(x) x ? HIGH : LOW

const int red = 3;
const int blue = 4;
const int green = 5;
const int speaker = 10;
const int ping = 7;

void setup()
{
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(speaker, OUTPUT);
}

void displayLight(int code)
{
  digitalWrite(red, F(code == 0));
  digitalWrite(blue, F(code == 1));
  digitalWrite(green, F(code == 2));
}

void playTone(long duration, int freq)
{
  duration *= 1000;
  int period = (1.0 / freq) * 100000;
  long elapsed_time = 0;
  while (elapsed_time < duration)
  {
    digitalWrite(speaker, HIGH);
    delayMicroseconds(period / 2);
    digitalWrite(speaker, LOW);
    delayMicroseconds(period / 2);
    elapsed_time += (period);
  }
}

void loop()
{
  long duration, inches, cm;

  pinMode(ping, OUTPUT);
  digitalWrite(ping, LOW);
  delayMicroseconds(2);
  digitalWrite(ping, HIGH);
  delayMicroseconds(5);
  digitalWrite(ping, LOW);

  pinMode(ping, INPUT);
  duration = pulseIn(ping, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if (cm < 50)
  {
    displayLight(0);
    playTone(300, 100);
  }
  else if (cm < 150)
  {
    displayLight(1);
    playTone(300, 200);
  }
  else
  {
    displayLight(2);
    playTone(300, 300);
  }

  delay(100);
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
