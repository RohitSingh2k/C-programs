/*
    Author  : Rohit Singh
    Purpose : To implement DIGITAL CLOCK.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hours=0,minute=0,sec=0,i;
    printf("Set/Enter time as HH:MM:SS format : ");
    scanf("%d:%d:%d",&hours , &minute ,&sec);
    start:
    for(; hours < 24 ; hours++)
    {
        for(; minute < 60 ; minute++)
        {
            for(; sec < 60 ; sec++ )
            {
                // This function will execute terminal or cmd command.
                system("clear");
                // Printing Format
                if( hours < 10)
                    printf("0%d:",hours);
                else
                    printf("%d:",hours);

                if(minute < 10)
                    printf("0%d:",minute);
                else
                    printf("%d:",minute);

                if(sec < 10)
                    printf("0%d ",sec);
                else
                    printf("%d ",sec);

                // Check for AM and PM notation.
                if( hours < 12)
                    printf("AM\n");
                else
                    printf("PM\n");

                for(i=0;i<800000000;i++);
            }
            sec = 0;
        }
        minute = 0;
    }
    hours = 0;
    goto start;
    return 0;
}
