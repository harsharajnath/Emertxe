#include<stdio.h>

struct Student
{
    int id;
    char name[20];
    char address[60];
};

int main()
{
    struct Student s1;
    printf("%zu\n", sizeof(struct Student));
    printf("%zu\n", sizeof(s1));

    return 0;
}
