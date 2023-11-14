#include<stdio.h>
typedef enum
{
    red,
    blue,
    green
} Color;
int main()
{
    Color c;
    printf("%zu\n", sizeof(Color));
    printf("%zu\n", sizeof(c));
    return 0;
}
