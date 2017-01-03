#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //minutes: 10
    //bottles: 120
    int minutes;
    
    printf("minutes: ");
    //scanf("%i", &minutes);
    minutes = GetInt();
    printf("bottles: %0.f\n",minutes*1.5*128/16);
}