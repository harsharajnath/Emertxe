#include <stdio.h>
struct Student
{
    int id;
    char name[20];
    char address[60];
};
int main()
{
    struct Student s1 = {10, "Tingu", "Bangalore"};
    struct Student s2;
    s2 = s1;
    return 0;
}
