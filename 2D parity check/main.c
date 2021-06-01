/*
    Author : Rohit Singh
    Purpose: To implement 2D parity check.
*/

#include<stdio.h>

int main()
{
    int bit,values,i,j,cout;
    printf("Enter the number of bits and number of values : ");
    scanf("%d %d",&bit,&values);
    int arr[values+1][bit+1];
    printf("Enter the values : ---------\n");

    for(i=0;i<values;i++)
        for(j=0;j<bit;j++)
            scanf("%d",&arr[i][j]);

    // Checking parity row wise.
    for(i=0;i<values;i++)
    {
        cout = 0;
        for(j=0;j<bit;j++)
        {
            cout += arr[i][j];
        }
        arr[i][j] = (cout%2 == 0)? 0 : 1;
    }

    // Checking parity colomn wise.
    for(i=0;i<bit+1;i++)
    {
        cout = 0;
        for(j=0;j<values;j++)
        {
            cout += arr[j][i];
        }
        arr[j][i] = (cout%2 == 0)? 0 : 1;
    }

    printf("Printing Reciever values : ----------\n");
    printf("Printing in matrix form\n");

    for(i=0;i<values+1;i++)
    {
        for(j=0;j<bit+1;j++)
        {
            printf("%2d",arr[i][j]);
        }
        printf("\n");
    }

    printf("Printing in linear form\n");

    for(i=0;i<values+1;i++)
    {
        for(j=0;j<bit+1;j++)
        {
            printf("%d",arr[i][j]);
        }
        printf(" ");
    }

    return 0;
}
