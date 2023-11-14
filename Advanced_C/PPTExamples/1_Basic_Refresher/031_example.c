#include <stdio.h>
int main()
{
    int array_org[5] = {1, 2, 3, 4, 5};
    int array_bak[5];
    int index;
    array_bak = array_org;
    if (array_bak == array_org)
    {
	printf("Copied \n" );
    }
    return 0;
}
