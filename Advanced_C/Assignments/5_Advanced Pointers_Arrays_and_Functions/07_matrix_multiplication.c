/*


Name: Harsharaj Nath
Date of Submission: 03-08-22
Description: WAP to find the product of given matrix.


Sample output:

Test case1:

Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :
1      2      3
1      2      3
1      2      3
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :

1      1     1
2      2     2
3      3     3
Product of two matrix :
14      14      14
14      14      14
14      14      14

Test case 2:

Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :
1      2      3
1      2      3
1      2      3
Enter number of rows : 2
Enter number of columns : 3
Matrix multiplication is not possible


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
#include <stdlib.h>

int matrix_mul(int **, int, int, int **, int, int, int **, int, int);           //function prototype for matrix_mul()

int main()
{
    int **mat_a, **mat_b, **result;
    
    int row1, col1, row2, col2;
    
    printf("Enter number of rows : ");
    scanf("%d", &row1);                                                         //reading row value of matrix A
    
    printf("Enter number of columns : ");
    scanf("%d", &col1);                                                         //reading col value of matrix A
    
    mat_a = malloc(row1 * sizeof(int));                                         //dynamically allocation memory for rows
    
    for (int i = 0; i < row1; i++)
    {
        mat_a[i] = malloc(col1 * sizeof(int));                                  //dynamically allocation memory for cols
    }
    
    printf("Enter values for %d x %d matrix :\n", row1, col1);
    
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < col1; j++)
        {
            scanf("%d", &mat_a[i][j]);                                          //reading the elements of the matrix A
        }
    }
    
    printf("Enter number of rows : ");
    scanf("%d", &row2);                                                         //reading row value of matrix B
    
    printf("Enter number of columns : ");
    scanf("%d", &col2);                                                         //reading col value of matrix B
    
    if( col1 == row2 )                                                          //condition check if matrix multiplication possible
    {
        mat_b = malloc(row1 * sizeof(int));                                     //dynamically allocation memory for rows
    
        for (int i = 0; i < row2; i++)
        {
            mat_b[i] = malloc(col2 * sizeof(int));                              //dynamically allocation memory for cols
        }
    
        printf("Enter values for %d x %d matrix :\n", row2, col2);
    
        for(int i = 0; i < row2; i++)
        {
            for(int j = 0; j < col2; j++)
            {
                scanf("%d", &mat_b[i][j]);                                      //reading the elements of the matrix B
            }
        }
        
        result = malloc(row1 * sizeof(int));                                    //dynamically allocation memory for rows of matrix Result
    
        for (int i = 0; i < row1; i++)
        {
            result[i] = malloc(col2 * sizeof(int));                             //dynamically allocation memory for cols of matrix Result
        }
        
        matrix_mul(mat_a, row1, col1, mat_b, row2, col2, result, row1, col2);   //function call
        
        printf("Product of two matrix : \n");
        
        for(int i = 0; i < row1; i++)                                           //printing the Result matrix
        {
            for(int j = 0; j < col2; j++)
            {
                printf("%d  ", result[i][j]);
            }
            printf("\n");
        }
        
        free(mat_a);                                                            //freeing dynamically allocated memory
        mat_a = NULL;
    
        free(mat_b);                                                            //freeing dynamically allocated memory
        mat_b = NULL;
    
        free(result);                                                           //freeing dynamically allocated memory
        result = NULL;
    }
    else
    {
        printf("Matrix multiplication is not possible\n");                      //error message
    }
    
    return 0;
}

int matrix_mul(int **mat_a, int row1, int col1, int **mat_b, int row2, int col2, int **result, int row3, int col3)              //function definition
{
    for(int i = 0; i < row1; i++)                                               //row traverse
    {
        for(int j = 0; j < col2; j++)                                           //col traverse
        {
            int prod = 0;
            int element_val = 0;
            int count = 0;
            int m = i;
            int n = 0;
            
            while (count != col1)                                               //calculating the element value
            {
                prod = mat_a[m][n] * mat_b[n][j];
                element_val = element_val + prod;
                
                n++;
                count++;
            }
                
            result[i][j] = element_val;                                         //storing the element value
        }
    }
    
    return 0;
}
