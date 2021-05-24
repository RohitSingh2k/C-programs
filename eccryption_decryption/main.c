/*
    Author  : Rohit Singh
    Purpose : To implement Encryption and Decryption.
*/
#include <stdio.h>
#include <stdlib.h>

// Array size
#define ARR_SIZE 400

int main()
{
   int i, x;
   char str[ARR_SIZE];

   // Taking the input string.
   printf("\nPlease enter a string:\t");
   fgets(str, ARR_SIZE, stdin);
   while (1)
   {
      // Printing Instructions
      printf("\nPlease choose following options:\n");
      printf("1 = Encrypt the string.\n");
      printf("2 = Decrypt the string.\n");
      printf("3 = Exit\n");

      // Taking user choice
      printf("Enter your Choice : ");
      scanf("%d", &x);

      switch (x)
      {
      case 1:
         // Encryption done here
         for (i = 0; (i < 100 && str[i] != '\0'); i++)
         {
            if (i % 2 == 0)
               str[i] = str[i] + 3;
            else
               str[i] = str[i] + 7;
         }
         printf("\nEncrypted string: %s\n", str);
         break;

      case 2:
         // Decryption done here
         for (i = 0; (i < 100 && str[i] != '\0'); i++)
         {
            if (i % 2 == 0)
               str[i] = str[i] - 3;
            else
               str[i] = str[i] - 7;
         }
         printf("\nDecrypted string: %s\n", str);
         break;

      case 3:
         exit(1);

      default:
         printf("\nError\n");

      }
   }
   return 0;
}
