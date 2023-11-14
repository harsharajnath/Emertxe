#include <stdio.h>
struct Student
{
    int id;
    char name[20];
    char address[60];
};
int main()
{
    struct Student s1;
    s1.id = 10;
    return 0;
}
