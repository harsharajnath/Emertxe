#include<stdio.h>
int main()
{
    FILE *fp;

    fp = fopen("text.txt","r");
    char ch;
    fseek(fp, 0, SEEK_END);
    printf("size = %ld\n", ftell(fp));
    fclose(fp);

    return 0;
}
