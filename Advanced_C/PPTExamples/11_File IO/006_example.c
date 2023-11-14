#include <stdio.h>
int main()
{
    int num1, num2;
    float num3;
    char str[10], oper, ch;
    FILE *fptr;
    if ((fptr = fopen("text.txt", "w+")) == NULL)
    {
	fprintf(stderr, "Can't open input file text.txt!\n");
	return 1;
    }
    fprintf(fptr, "%d %c %d %s %f\n", 2, '+', 1, "is", 1.1);
    rewind(fptr);
    fscanf(fptr, "%d %c %d %s %f", &num1, &oper, &num2, str, &num3);
    printf("%d %c %d %s %f\n", num1, oper, num2, str, num3);
    fclose(fptr);
    return 0;
}
