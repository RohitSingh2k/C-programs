/*
	Author     : Rohit Singh
	Purpose  : To show the implementation opf time 
*/

#include <stdio.h>
// Time header file.
#include <time.h>

// tm structure defines in time.h
typedef struct tm timestruct;

int main(int argc, char **argv)
{
	// time_t is a data type which stores time
	time_t mytime;
	
	// time() function initialise time
	time(&mytime);
	
	// ctime() will convert time into string.
	printf("Time function print's  this type of output (%s)\n",ctime(&mytime));
	
	// localtime will initialise pointer to tm structure.
	timestruct *thistime = localtime(&mytime);
	
	/*	Printing today's date
		tm_year will return number of years from 1900.
		tm_mon start with 0 As JANUARY = 0;
	*/
	printf("Today's Date is  : %d/%d/%d\n",thistime->tm_mday,thistime->tm_mon + 1,1900 + thistime->tm_year);
	
	// clock() return total number of cpuclock during full execution of a program.
	int cpu_clock_time = clock();
	printf("Total CPU clocks  : %d\n", cpu_clock_time);
	
	// CLOCK_PER_SEC constant will return cpu clock per second.
	printf("Clock per sec : %d\n",CLOCKS_PER_SEC);
	
	// This will result total time of program execution.
	printf("Program Execution time :  %f s\n", (float) cpu_clock_time / CLOCKS_PER_SEC );
	
	return 0;
}
