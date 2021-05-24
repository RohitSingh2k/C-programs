/*
    Athour : Rohit Singh
    Purpose : To demonstrate the DESIGNATED INITIALIZATION of an array.
*/
#include<stdio.h>

int main()
{
    // Initialisation of 2D array
    int i,j,arr[10][10] = {[0 ... 9][0 ... 9]=2};
    printf("Example of two Dimentional array...\n");

    // Printing 2D array
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }

    printf("Example of one Dimentional array...\n");
    // Initialising the 1D array.
    int array[10] = {[0 ... 9]=3};
    // Printing 1D array
    for(i=0;i<10;i++)
        printf("%d ",array[i]);
    return 0;
}
