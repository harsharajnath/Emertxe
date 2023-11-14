#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *input_fp;
    input_fp = fopen("text.txt", "r");
    if (input_fp == NULL)
    {
	return 1;
    }
    fclose(input_fp);
    return 0;
}
