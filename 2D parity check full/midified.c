
/*
    Author : Rohit Singh
    Purpose: To implement 2D parity check.
*/

#include<stdio.h>

int main()
{
    int bit,values,i,j,cout;
    printf("Sender side:--------------\n");

    printf("Enter the number of bits and number of values : ");
    scanf("%d %d",&bit,&values);
    int arr[values+1][bit+1];
    printf("Enter the values : ---------\n");

    // Taking data in sender side
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

    // Printing sending values
    printf("Printing Sending values in matrix form\n");
    for(i=0;i<values+1;i++)
    {
        for(j=0;j<bit+1;j++)
        {
            printf("%2d",arr[i][j]);
        }
        printf("\n");
    }

    printf("Reciever side:----------\n");
    int rec[values + 1][bit + 1];
    for(i=0;i<=values;i++)
    {
        for(j=0;j<=bit;j++)
        {
            scanf("%d",&rec[i][j]);
        }
    }
    // Reciever side logic
    int f = 0;
    for(i = 0; i<=values; i++)
    {
        int cnt = 0;
        for(j = 0; j <=bit ; j++)
        {
            cnt += rec[i][j];
        }
        if(cnt%2!=0)
        {
            f = 1;
            printf("Error at %d row\n",i);
        }
    }

    for(i = 0; i<=bit; i++)
    {
        int cnt = 0;
        for(j = 0; j <=values ; j++)
        {
            cnt += rec[j][i];
        }
        if(cnt%2!=0)
        {
            f = 1;
            printf("Error at %d colomn\n",i);
        }
    }
    if(f == 0)
    {
        printf("Data Accepted\n");
    }
    return 0;
}
