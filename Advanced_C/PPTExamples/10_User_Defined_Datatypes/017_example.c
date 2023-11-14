#include<stdio.h>
struct Nibble
{
    unsigned lower : 4;
    unsigned upper : 4;
};
int main()
{
    struct Nibble nibble;
    printf("%zu\n", sizeof(nibble));
    return 0;
}
