#include<stdlib.h>
struct Student
{
    int id;
    char *name;
    char *address;
};
struct Student data(void)
{
    struct Student s;
    s.name = (char *) malloc(30 * sizeof(char));
    s.address = (char *) malloc(150 * sizeof(char));
    return s;
}
int main()
{
    struct Student s1;
    s1 = data();
    return 0;
}
