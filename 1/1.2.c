#include "mbed.h"
BusOut myleds(LED1, LED2, LED3, LED4);
int main()
{
    while (1)
    {
        for (int i = 0; i < 16; i++)
        {
            myleds = i;
            if (i % 2 == 1)
            {
                printf("Waiting 1s for %d\n", i);
                wait(1);
            }
            else
            {
                printf("Waiting 2s for %d\n", i);
                wait(2);
            }
        }
    }
}