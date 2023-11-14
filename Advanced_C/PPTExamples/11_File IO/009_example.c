#include <stdio.h>
struct Data
{
    int num1;
    char oper;
    int num2;
    char str[10];
    float num3;
};
int main()
{
    struct Data d1 = {2, '+', 1, "is", 1.1};
    struct Data d2;
    FILE *fptr;
    if ((fptr = fopen("text.txt", "w+")) == NULL)
    {
	fprintf(stderr, "Can't open input file text.txt!\n");
	return 1;
    }
    fwrite(&d1, sizeof(d1), 1, fptr);
    rewind(fptr);
    fread(&d2, sizeof(d2), 1, fptr);
    printf("%d %c %d %s %f\n", d2.num1, d2.oper, d2.num2, d2.str, d2.num3);
    fclose(fptr);
    return 0;
}
