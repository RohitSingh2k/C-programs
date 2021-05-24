/*
    Author  : Rohit Singh
    Purpose : To implement tic tac toe game
*/
#include <stdio.h>
#include <stdlib.h>

void displayTable();
int checkForWin();
int markBlock(char);

// Declaring char array table.
char section[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int player,choice;

int main()
{
    int gameStatus;

    char mark;

    player = 1;

    do
    {
      displayTable();

      // change turns
      player = (player % 2) ? 1 : 2;

      // get input
      printf("Player %d, enter a number: ", player);
      scanf("%d", &choice);

      // set the correct character based on player turn
      mark = (player == 1) ? 'X' : 'O';

      // set board based on user choice or invalid choice
      markBlock(mark);

      gameStatus = checkForWin();

      player++;

    }while (gameStatus == -1);

    if (gameStatus == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");
    return 0;
}

/******************************************************
This Function Displays the table
******************************************************/
void displayTable()
{
    system("clear");
    printf("\tTic Tac Toe\n\n");
    printf("Player 1 = X     Player 2 = O\n\n\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",section[1],section[2],section[3]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",section[4],section[5],section[6]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",section[7],section[8],section[9]);
    printf("   |   |   \n");
}

/******************************************************
This Function check for winning condition
******************************************************/
int checkForWin()
{
    int returnValue = 0;
    if(section[1] == section[2] && section[2] == section[3])
        returnValue = 1;
    else if(section[4] == section[5] && section[5] == section[6])
        returnValue = 1;
    else if(section[7] == section[8] && section[8] == section[9])
        returnValue = 1;
    else if(section[1] == section[4] && section[4] == section[7])
        returnValue = 1;
    else if(section[2] == section[5] && section[5] == section[8])
        returnValue = 1;
    else if(section[3] == section[6] && section[6] == section[9])
        returnValue = 1;
    else if(section[1] == section[5] && section[5] == section[9])
        returnValue = 1;
    else if(section[3] == section[5] && section[5] == section[7])
        returnValue = 1;

    else if( section[1] != '1' && section[2] != '2' && section[3] != '3'
            && section[4] != '4' && section[5] != '5' && section[6] != '6'
            && section[7] != '7' && section[8] != '8' && section[9] != '9')
        returnValue = 0;
    else
        returnValue = -1;
    return returnValue;
}

/******************************************************
This Function mark each section with the user choice
******************************************************/
int markBlock(char mark)
{
    char a;
    if( choice == 1 && section[1] == '1')
        section[1] = mark;
    else if( choice == 2 && section[2] == '2')
        section[2] = mark;
    else if( choice == 3 && section[3] == '3')
        section[3] = mark;
    else if( choice == 4 && section[4] == '4')
        section[4] = mark;
    else if( choice == 5 && section[5] == '5')
        section[5] = mark;
    else if( choice == 6 && section[6] == '6')
        section[6] = mark;
    else if( choice == 7 && section[7] == '7')
        section[7] = mark;
    else if( choice == 8 && section[8] == '8')
        section[8] = mark;
    else if( choice == 9 && section[9] == '9')
        section[9] = mark;

    else
    {
        printf("Invalid move");
        player--;
    }
}
