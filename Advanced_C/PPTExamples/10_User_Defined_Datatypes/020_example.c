union Test
{
    char option;
    int id;
    double height;
};
int main()
{
    union Test temp_var;
    temp_var.height = 7.2;
    temp_var.id = 0x1234;
    temp_var.option = '1';
    return 0;
}
