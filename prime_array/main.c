/*
    Author  : Rohit Singh
    Purpose : To construct an array having all prime numbers from 1-100/
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    // Initialising prime array nad index.

    int primeNumbers[50] = {};
    int primeIndex = 2,i,j;

    bool isPrime;

    // Set first two value to the prime array.

    primeNumbers[0] = 2;
    primeNumbers[1] = 3;

    // Here we iterating over all odd numbers because even number can't be prime.

    for(i = 5; i <100 ; i += 2 )
    {
        isPrime = true;

        // Check whether i is divisible or not by all value till i/2.

        for(j = 2 ; isPrime && j < (int) i/2 ; j++)
            if(i % j == 0)
                isPrime = false;

        // Appending the prime value to the prime array.

        if(isPrime)
            primeNumbers[primeIndex++] = i;
    }

    // printing the prime array.

    for(i = 0 ; i < 50 && primeNumbers[i] ; i++)
        printf("%d ",primeNumbers[i]);

    return 0;
}
