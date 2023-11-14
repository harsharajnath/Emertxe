#include <stdio.h>
int main()
{
    FILE *fptr;
    char ch;
    fptr = fopen("file.txt", "w");
    ch = fgetc(fptr);/* This should fail since reading a file in write mode*/
    if (ferror(fptr))
	fprintf(stderr, "Error in reading from file : file.txt\n");
    clearerr(fptr);
    /* This loop should be false since we cleared the error indicator */
    if (ferror(fptr))
	fprintf(stderr, "Error in reading from file : file.txt\n");
    fclose(fptr);
    return 0;
}
