/*
	Author  : Rohit Singh
	Purpose : To implement CRC error check.
*/
#include <stdio.h>
#include <math.h>

// Binary to decimal converter.
long long binary_to_decimal(long long n) {
    long long dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}

// Decimal to binary converter.
long long decimal_to_binary(long long n) {
    long long bin = 0;
    int rem, i = 1, step = 1;
    while (n != 0) {
        rem = n % 2;
   		n /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}

int main()
{
	long long value,i,len_of_value,temp,len_of_div,divisor;

	// Taking Sending value and divisor as input for sender side.
	printf("###################### SENDER SIDE ######################\n\n");
	printf("\tEnter the value to send : ");
	scanf("%lld",&value);
	value = binary_to_decimal(value);
	printf("\tEnter the divisor value : ");
	scanf("%lld",&divisor);
	divisor = binary_to_decimal(divisor);

	// Calculating bit length of divisor and sending value
	len_of_div = floor(log(divisor)/log(2)) + 1;
	len_of_value = floor(log(value)/log(2)) + 1;

	// Appending extra zero's to value
	value <<= (len_of_div - 1);

	// making an extra copy of main value for remainder addition.
	long long main_value = value;

	// Calculating remainder.
	while( len_of_div < len_of_value )
	{
		len_of_value = floor(log(value)/log(2)) + 1;
		temp = divisor << (len_of_value - len_of_div);
		value = value ^ temp;
	}

	// Adding remainder to main value.
	printf("\tRemainder is %lld\n",decimal_to_binary(value));
	main_value += value;
	printf("\tSending value is %lld\n\n",decimal_to_binary(main_value));

	// Taking Sending value and divisor as input for reciever side.
	printf("##################### RECIEVER SIDE #####################\n\n");
	printf("\tEnter the recieve value : ");
	scanf("%lld",&value);
	value = binary_to_decimal(value);
	printf("\tEnter the divisor value : ");
	scanf("%lld",&divisor);
	divisor = binary_to_decimal(divisor);

	// Calculating bit length of divisor and recieved value
	len_of_div = floor(log(divisor)/log(2)) + 1;
	len_of_value = floor(log(value)/log(2)) + 1;


	main_value = value;

	// Calculating remainder value.
	while( len_of_div < len_of_value )
	{
		len_of_value = floor(log(value)/log(2)) + 1;
		temp = divisor << (len_of_value - len_of_div);
		value = value ^ temp;
	}

	int final = value;

	// If final remainder is non-zero then rejected alse accepted.
	if(final)
		printf("\tREJECTED\n");
	else
		printf("\tACCEPTED\n");
	return 0;
}
