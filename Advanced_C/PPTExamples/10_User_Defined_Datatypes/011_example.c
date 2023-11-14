#include <stdio.h>
struct Student
{
    int id;
    char name[30];
    char address[150];
};
void data(struct Student *s)
{
    s->id = 10;
}
int main()
{
    struct Student s1;
    data(&s1);
    return 0;
}
