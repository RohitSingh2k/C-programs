/*
  Author : Rohit Singh
  Purpose: To implement wrapped checksum error checking.
*/
#include <stdio.h>
#include <stdlib.h>

int cout = 0;

// This function calculates ones complement.
void one_comp(int a[10], int size) {
 int i;
 for (i = 0; i < size; i++) {
   if (a[i] == 0)
     a[i] = 1;
   else
     a[i] = 0;
 }
}

// This function calculate sum
int *get_sum(int a[10], int b[10], int size) {
 int *sm, sum[10], cin = 0, i, one[10];
 sm = (int *)malloc(sizeof(int) * size);

 // Here we implement 3 bit addition i.e full adder concept.
 for (i = size - 1; i >= 0; i--) {
   sum[i] = a[i] ^ b[i] ^ cin;
   cout = (b[i] && a[i]) || (b[i] && cin) || (a[i] && cin);
   cin = cout;
 }

 // Mapping sum array into pointer.
 for (i = 0; i < size; i++) {
   *(sm + i) = sum[i];
 }
 // If carry bit if 1 at last then add 1 into the bit.
 if (cout) {
   for (i = 0; i < size - 1; i++)
     one[i] = 0;
   one[i] = 1;
   cin = 0;
   sm = get_sum(sum, one, size);
 }

 return sm;
}

void main() {
 char fdata[10], sdata[10], cdata[10];
 int fnum[10], snum[10], cnum[10], *sum, size, i, c, f = 0;
 printf("--Sender's Side--\n");
 printf("enter the no. of bits = ");
 scanf("%d", &size);
 printf("Enter first data = ");
 scanf("%s", fdata);
 printf("Enter second data = ");
 scanf("%s", sdata);
 sum = (int *)malloc(sizeof(int) * size);
 for (i = 0; i < size; i++) {
   fnum[i] = (int)(fdata[i] - '0');
   snum[i] = (int)(sdata[i] - '0');
 }

 sum = get_sum(fnum, snum, size);
 one_comp(sum, size);

 printf("Check-Sum= ");
 for (i = 0; i < size; i++)
   printf("%d", sum[i]);
 printf("\n--Receiver's Side--\n");
 printf("enter the no. of bits = ");
 scanf("%d", &size);
 printf("Enter first data = ");
 scanf("%s", fdata);
 printf("Enter second data = ");
 scanf("%s", sdata);
 printf("Enter check-sum = ");
 scanf("%s", cdata);
 for (i = 0; i < size; i++) {
   fnum[i] = (int)(fdata[i] - '0');
   snum[i] = (int)(sdata[i] - '0');
   cnum[i] = (int)(cdata[i] - '0');
 }
 sum = get_sum(fnum, snum, size);

 sum = get_sum(sum, cnum, size);

 one_comp(sum, size);
 for (i = 0; i < size; i++)
   if (sum[i]) {
     f = 1;
     printf("Rejected");
     break;
   }
 if (!f)
   printf("Accepted");
}

