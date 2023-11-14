#include<stdio.h>

int main()

{

    int arr[5] = {10, 20, 30, 40, 50};
    int temp, i;

    char opt;

    do {

        temp = arr[0];
        for(i = 0; i < 4; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[4] = temp;

        for(i = 0; i < 5; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n");

        printf("Do you want to continue? (y/n) \n");

        scanf("\n%c", &opt);

    }
    while (opt == 'y');


    return 0;
}