/*
    Author  : Rohti Singh
    purpose : To see how strtok() works.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    // Our main string or string after strtok().
    char str[] = "This is a sentence";

    // It's a delimeter or saparator character.
    const char delimeter[2] = " ";

    // char pointer for getting each token.
    char *token;

    // Call strtok with 1st pram as main string and 2nd pram as delimeter.
    token = strtok(str,delimeter);

    /*
        our string after 1st strtok() call
        "This\000is a sentence"
    */
    while(token != NULL)
    {
        printf("%s\n",token);

        /*
            Here in strtok we say that we give you nothing more
            i.e NULL and just iterate over previous string with same delimeter.
        */
        token = strtok(NULL,delimeter);
    }

    /*
        Our main string after strtok()
        "This\000is\000a\000sentence"
    */
    return 0;
}
