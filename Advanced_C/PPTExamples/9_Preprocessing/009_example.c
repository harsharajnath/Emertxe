#include <stdio.h>
#define SWAP(a, b)	\
{			\
    int temp = a;	\
    a = b;		\
    b = temp;		\
}			\

int main()
{
    int n1 = 10, n2 = 20;

    SWAP(n1, n2);
    printf("%d %d\n", n1, n2);

    SWAP(n1, n2);
    printf("%d %d\n", n1, n2);

    return 0;
}
