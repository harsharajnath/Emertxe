#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr;
    char ch;
    fptr = fopen("/etc/shells", "r");
    /* Need to do error checking on fopen() */
    printf("File offset is at -> %ld\n\n", ftell(fptr));
    printf("--> The content of file is <--\n");
    while ((ch = fgetc(fptr)) != EOF)
	fputc(ch, stdout);
    printf("\nFile offset is at -> %ld\n", ftell(fptr));
    fclose(fptr);
    return 0;
}
