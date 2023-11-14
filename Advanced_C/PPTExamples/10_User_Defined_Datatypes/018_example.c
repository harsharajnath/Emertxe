#include<stdio.h>
struct Nibble
{
    char lower : 4;
    char upper : 4;
};
int main()
{
    struct Nibble nibble;
    nibble.upper = 0x0A;
    nibble.lower = 0x02;
    printf("%d\n", nibble.upper);
    printf("%d\n", nibble.lower);
    return 0;
}
