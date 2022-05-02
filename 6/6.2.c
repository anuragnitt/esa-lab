#define F(x) x ? HIGH : LOW

const int led = 4;
const int pir = 3;
const int speaker = 10;

int totalMovements = 0;
bool isMoving = false;

void setup()
{
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    pinMode(pir, INPUT);
    pinMode(speaker, OUTPUT);
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
    int pirStat = digitalRead(pir);
    if (pirStat == HIGH)
    {
        if (!isMoving)
        {
            playTone(300, 300);
            totalMovements += 1;
            Serial.print("Total movements: ");
            Serial.print(totalMovements);
            Serial.print("\n");
            isMoving = true;
        }
        digitalWrite(led, HIGH);
    }
    else
    {
        isMoving = false;
        digitalWrite(led, LOW);
    }
}
