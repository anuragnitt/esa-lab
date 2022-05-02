#include "mbed.h"
PwmOut speaker(p21);
int main()
{
    int i;
    while (1)
    {
        for (i = 0; i < 26; i++)
        {
            speaker.period(1.0 / 259.0);
            speaker = float(i) / 500.0;
            wait(0.5);
            speaker.period(1.0 / 340.0);
            wait(0.5);
        }
        for (i = 26; i >= 0; i--)
        {
            speaker.period(1.0 / 259.0);
            speaker = float(i) / 500.0;
            wait(0.5);
            speaker.period(1.0 / 440.0);
            wait(0.5);
        }
    }
}
