#include <stdio.h>

int main() {

    int size, sum = 0, i;
    float avg;

    printf("Enter the size of array: \n");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the array elements: \n");
    for(i = 0; i < size; i++)

    {

        scanf("%d", &arr[i]);

    }
    for(i = 0; i < size; i++)

    {

        sum += arr[i];

    }

    avg = (float) sum / size;

    printf("Average = %g\n", avg);

    return 0;

}