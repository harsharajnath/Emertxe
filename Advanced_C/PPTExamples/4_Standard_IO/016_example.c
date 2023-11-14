#include <stdio.h>

int main()
{
    int hours;

    int mins;

    int secs;

    printf("Please enter Time as HH:MM:SS\n");

    scanf("%d%*c%d%*c%d", &hours, &mins, &secs);
    printf("%d:%d:%d\n", hours, mins, secs);

    return 0;

}