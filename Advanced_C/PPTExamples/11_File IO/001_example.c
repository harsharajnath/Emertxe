#include <stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("text.txt", "r");
    fclose(fp);
    return 0;
}
