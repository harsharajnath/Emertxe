typedef struct _Student
{
    int id;
    char name[30];
    char address[150];
} Student; 

void data(Student s)
{
    s.id = 10;
}
int main()
{
    Student s1;
    data(s1);
    return 0;
}
