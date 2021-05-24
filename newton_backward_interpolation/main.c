/*
    Author  : Rohit Singh
    Purpose : To implement Newton's Backward Interpolation Formula.
*/

#include <stdio.h>
#include <stdlib.h>

// Function declation for factorial function.
int fact(int);

int main()
{
    // Declare required variable.
    int i,j,arr_size;
    float r, interpolation, temp, interpolatingPoint;

    // Take the size of total number of points.
    printf("Enter the total number of points : ");
    scanf("%d",&arr_size);

    // Initialising x, y and Del array.
    float x[arr_size], y[arr_size][arr_size], del_value[arr_size];

    // Taking the values of x and y points.
    for(i=0;i<arr_size;i++)
    {
        printf("x[%d] = ", i + 1 );
        scanf("%f",&x[i]);
        printf("y[%d] = ", i + 1 );
        scanf("%f",&y[0][i]);
    }

    // Calculating del values.
    del_value[0] = y[0][arr_size - 1];

    for( i = 1 ; i < arr_size ; i++ )
    {
        for( j = 1 ; j < arr_size ; j++ )
        {
            if(i <= j)
                y[i][j] = y[i - 1][j] - y[i -1][j - 1];
            else
                y[i][j] = 0.0;
        }
        del_value[i] = y[i][arr_size - 1];
    }

    // Taking the interpolating point.
    printf("Enter the interpolating Point : ");
    scanf("%f",&interpolatingPoint);

    // Calculating the value of r.
    r = ( (interpolatingPoint - x[arr_size - 1]) / (x[1] - x[0]) );

    // Calculating interpolation for the given interpolating point.
    interpolation = del_value[0];

    for( i = 1 ; i < arr_size ; i++ )
    {

        temp = del_value[i];

        for( j = 0 ; j < i ; j++ )
                temp *= r + j;

        if(temp)
        {
            temp /= fact(i);
            interpolation += temp;
        }

    }

    // Printing the interpolation.
    printf("For x = %.2f the value of y = %.2f \n", interpolatingPoint, interpolation);

    return 0;
}

// Function definition for calculation of factorial
int fact(int x)
{
    if(x == 1)
        return 1;
    else
        return ( x * fact(x - 1) );
}
