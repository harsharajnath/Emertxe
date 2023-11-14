#include<stdio.h>
struct Nibble
{
    char lower : 4;
    char upper : 4;
};
int main()
{
    struct Nibble nibble = {0x02, 0x0A};
    printf("%#o\n", nibble.upper);
    printf("%#x\n", nibble.lower);
    return 0;
}
