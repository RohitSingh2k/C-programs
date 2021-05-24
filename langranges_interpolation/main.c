/*
    Author  : Rohit Singh
    Purpose : To implement Langranges Interpolation formula
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declaring and initialising the required variables.

    int i,j,arr_size;
    float interpolation = 0.0, temp = 1.0, interpolatingPoint = 0.0;

    // Taking the array size.

    printf("Enter the total number of points : ");
    scanf("%d",&arr_size);

    // Declaring x and y Array.

    float x[arr_size],y[arr_size];

    // Taking values into the x and y array.

    for(i = 0 ; i < arr_size ; i++ )
    {
        printf("x[%d] = ",i);
        scanf("%f",&x[i]);
        printf("y[%d] = ",i);
        scanf("%f",&y[i]);
    }

    // Taking the interpolating point.

    printf("Enter the point for finding interpolation : ");
    scanf("%f",&interpolatingPoint);

    // Calculating Inter[polation for given interpolating point.

    for( i = 0 ; i < arr_size ; i++ )
    {

        for( j = 0 ; j < arr_size ; j++ )
        {

            if( i == j )
                continue;
            else
                temp *= ( (interpolatingPoint - x[j]) / (x[i] - x[j]) );

        }

        temp *= y[i];
        interpolation += temp;
        temp = 1.0;

    }

    // Printing the Interpolation.

    printf("For x = %.2f value of y = %.2f\n",interpolatingPoint,interpolation);

    return 0;
}
