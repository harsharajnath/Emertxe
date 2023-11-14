#include <stdio.h>
#define WARN_IF(EXP)					\
do							\
{							\
    x--;						\
    if (EXP)						\
    {							\
	fprintf(stderr, "Warning: " #EXP "\n");		\
    }							\
} while (x);						\

int main()
{
    int x = 5;
    WARN_IF(x == 0);
    return 0;
}
