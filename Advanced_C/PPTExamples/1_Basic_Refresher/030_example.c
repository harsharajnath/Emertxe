#include <stdio.h>
int main()
{
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5] = {1, 2};
    int array3[] = {1, 2};
  //int array4[]; /* Invalid */
    printf("%zu\n", sizeof (array1));
    printf("%zu\n", sizeof (array2));
    printf("%zu\n", sizeof (array3));
    return 0;
}
