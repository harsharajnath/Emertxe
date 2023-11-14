#include<stdio.h>
struct Nibble
{
    unsigned char lower : 4;
    unsigned char upper : 4;
};
int main()
{
    struct Nibble nibble;
    printf("%zu\n", sizeof(nibble));
    return 0;
}
