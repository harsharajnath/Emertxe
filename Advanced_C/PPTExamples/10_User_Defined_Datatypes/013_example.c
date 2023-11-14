#include <stdio.h>
struct Student
{
    char ch1;
    int num;
    char ch2;
};
int main()
{
    struct Student s1;
    printf("%zu\n", sizeof(struct Student));
    return 0;
}
