#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#endif //TIC_TAC_TOE_H


int menu()
{
    int play = 0;
    printf("- Hello, Welcome to my Tic Tac Toe Game in C \n");
    printf("- Press 1 to play the game\n");
    printf("- Press 2 to see the rule\n");
    printf("- Press 3 to quit the game\n");
    scanf("%d", &play);
    switch (play)
      {
          case 1:
              system("clear");
              return 1;

          case 2:
              printf("The rule of the game is simple\n");
              printf("You need to place a X on the board\n");
              printf("Your goal is to have a line of X on the board\n");
              printf("The line can be horizontal, vertical or diagonal\n");
              printf("But be careful because the BOT can counter you and even Win the game\n");

              sleep(2);
              system("clear");
              printf("This is a preview of the board you'll play on\n");

              printf(" 1 | 2 | 3 \n");
              printf("-----------\n");
              printf(" 4 | 5 | 6 \n");
              printf("-----------\n");
              printf(" 7 | 8 | 9 \n");

              sleep(3);
              system("clear");
              return 1;

          case 3:
              return 0;

          default:
              return 0;

      }
}

int winCondition(char board[3][3])
{
    int i =0;
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if(((board[i][0] == 'X' && board[i][1] == 'X' )||( board[i][0] == 'O'&& board[i][1] == 'O'))) {
                return 1;
            }
            else{
                return 0;
            }
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if((board[0][i] == 'X' && board[1][i] == 'X' )|| (board[0][i] == 'O' && board[1][i] == 'O')) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if((board[0][0] == 'X' && board[1][1] == 'X') || (board[0][0] == 'O' && board[1][1] == 'O')) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if((board[0][2] == 'X' && board[1][1] == 'X') || (board[0][2] == 'O' && board[1][1] == 'O')) {
            return 1;
        }
        else {
            return 0;
        }
    }
    return 0;
}

int drawCondition(char board[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O' && board[i][j]!=' ')
            {
                return 0;
            }
        }
    } return 1;
}

char showBoard (char board[3][3])
{
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);

    sleep(1);
    return 1;
}

int botMoove(char board[3][3])
{
    retry:
    srand(time(NULL));
    int botMoove = rand() % 9 + 1;
    int row,col;
    row = (botMoove - 1) / 3;
    col = (botMoove - 1) % 3;
    if(board[row][col] == 'X' || board[row][col] == 'O')
    {
        goto retry;
    }
    else
    {
        board[row][col] = 'O';
    }
    return 1;
}