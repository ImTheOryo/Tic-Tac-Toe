#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include "tic-tac-toe.h"

char board[3][3] =
{
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};



int main()
{
    int playercheck = 0;
    menu();
    int playerChoice;

    while(1)
    {
        retry:
        showBoard(board);
        printf("Enter a number between 1 and 9 :\n");
        scanf("%d",&playerChoice);
        if(playerChoice < 1 || playerChoice > 9)
        {
            printf("Please put a number between 1 and 9 !\n");
            goto retry;
        }
        int row = (playerChoice - 1) / 3;
        int col = (playerChoice - 1) % 3;
        //printf(" row = %d col = %d \n", row, col);

        if(board[row][col] == 'X' || board[row][col] == 'O')
        {
            printf("Don't try to cheat \n");
            goto retry;
        }
        else
        {
            board[row][col] = 'X';
        }
        playercheck ++;
        showBoard(board);
        sleep(1);
        system("clear");
        if (playercheck > 8)
        {
            if(drawCondition(board))
            {
                printf("It's a draw !!\n");
                break;
            }
        }
        if(winCondition(board))
        {
            if(playercheck % 2 == 1)
            {
                printf("You win !!\n");
                break;
            }
            else
            {
                printf("You lose !!\n");
                break;
            }
        }
        botMoove(board);
        playercheck ++;
        if(winCondition(board))
        {
            if(playercheck % 2 == 1)
            {
                printf("You win !!\n");
                break;
            }
            else
            {
                printf("You lose !!\n");
                break;
            }
        }

    }
    return 0;
}