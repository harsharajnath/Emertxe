#include <stdio.h>
int main()
{
    int num1, num2;
    FILE *fptr;
    if ((fptr = fopen("text.txt", "w+")) == NULL)
    {
	fprintf(stderr, "Can't open input file text.txt!\n"); return 1;
    }
    scanf("%d%d", &num1, &num2);
    fwrite(&num1, sizeof(num1), 1, fptr);
    fwrite(&num2, sizeof(num2), 1, fptr);
    rewind(fptr);
    fread(&num1, sizeof(num1), 1, fptr);
    fread(&num2, sizeof(num2), 1, fptr);
    printf("%d %d\n", num1, num2);
    fclose(fptr);
    return 0;
}
