#define F(x) x ? HIGH : LOW

int pins[] = {13, 12, 11, 10};

void setup()
{
    for (int i = 0; i < 4; i++)
        pinMode(pins[i], OUTPUT);
}
void show(int x)
{
    int vals[] = {F(x & 8), F(x & 4), F(x & 2), F(x & 1)};
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(pins[i], vals[i]);
    }
}
void loop()
{
    for (int i = 0; i < 16; i += 2)
    {
        show(i);
        delay(1000);
    }
}