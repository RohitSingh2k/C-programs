/*
    Author  : Rohit Singh
    Purpose : To Print transpose of a 2D Matrix.
*/
#include <stdio.h>
#include <stdlib.h>
#define ROW 4
#define COLOMN 5

int main()
{
    // Initialising the 2D Array.
    int i,j,arr[ROW][COLOMN] = {
                        {1,2,3,4,5},
                        {6,7,8,9,10},
                        {11,12,13,14,15},
                        {16,17,18,19,20}
                    };
    printf("Martix is-----\n");
    // printing the matrix

    for( i = 0 ; i < ROW ; i++)
    {

        for( j = 0 ; j < COLOMN ; j++ )
            printf("%4d ",arr[i][j]);

        printf("\n");

    }

    printf("Transpose of the Martix is-----\n");
    // printing the transpose matrix

    for( i = 0 ; i < COLOMN ; i++)
    {

        for( j = 0 ; j < ROW ; j++ )
            printf("%4d ",arr[j][i]);

        printf("\n");

    }
    return 0;
}
