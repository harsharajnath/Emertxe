#include<stdio.h>
typedef enum
{
    e_red = 1,
    e_blue = 4,
    e_green
} Color;
int main()
{
    Color e_white = 0, e_black;
    printf("%d\n", e_white);
    printf("%d\n", e_black);
    printf("%d\n", e_green);
    return 0;
}
