
#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

void printBoard();
int checkWin();

void customSystem()
{
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux and macOS
#endif
}

int rd()
{
    int rem;
A:
    rem = rand() % 7;
    if (rem == 0)
        goto A;
    else
        return rem;
}
void displaychart(int curp, char player[4])
{
    int i, j, t, c, sft = 0, diceres, pos1, pos2;

    if (curp == 100)
    {
        printf("*****Congratulations*****\n\n\nPlayer %s wins\n", player);
        exit(0);
    }

    for (i = 10; i > 0; i--)
    {
        t = i - 1;
        if ((sft % 2) == 0)
        {
            c = 0;
            for (j = 10; j >= 1; j--)
            {
                diceres = (i * j) + (t * c++);

                if (curp == diceres)
                    printf("%s\t", player);
                else
                    printf("%d\t", diceres);
            }
            sft++;
        }
        else
        {
            c = 9;
            for (j = 1; j <= 10; j++)
            {
                diceres = (i * j) + (t * c--);

                if (curp == diceres)
                    printf("%s\t", player);
                else
                    printf("%d\t", diceres);
            }

            sft++;
        }
        printf("\n\n");
    }

    printf("--------------------------------------------------------------------------\n");
}
void snakeMain()
{
    customSystem();
    int i, dice, cur_pos1 = 0, cur_pos2 = 0;
    char ch;
    while (1)
    {
        printf("\n\n");
        printf("		** SNAKE AND LADDER GAME** \n\n       ");
        printf("Snakes:- 25 to 9,\t 65 to 40,\t 99 to  1.\nLadder:- 13 to 42,\t 60 to 83,\t 70 to 93.\n");
        printf("Choose your option\n");
        printf("1. Player 1 plays\n");
        printf("2. Player 2 plays\n");
        printf("3. Exit\n");
        scanf("%s", &ch);

        switch (ch)
        {

        case '1':
            dice = rd();
            customSystem();
            printf("\t\t\t\tDice = %d\n\n", dice);
            if (dice == 6)
                printf("Dice=6: You have earned a chance to play one more time.\n");
            cur_pos1 = dice + cur_pos1;
            if (cur_pos1 < 101)
            {
                if (cur_pos1 == 99)
                {
                    displaychart(1, "$P1$"); // snake
                }
                if (cur_pos1 == 65)
                {
                    displaychart(40, "$P1$"); // snake
                }
                if (cur_pos1 == 25)
                {
                    displaychart(9, "$P1$"); // snake
                }
                if (cur_pos1 == 70)
                {
                    displaychart(93, "$P1$"); // ladder
                }
                if (cur_pos1 == 60)
                {
                    displaychart(83, "$P1$"); // ladder
                }
                if (cur_pos1 == 13)
                {
                    displaychart(42, "$P1$"); // ladder
                }
                else
                {
                    displaychart(cur_pos1, "$P1$");
                }
            }
            else
            {
                cur_pos1 = cur_pos1 - dice;
                printf("Range exceeded of Player 1.\n");
                displaychart(cur_pos1, "$P1$");
            }
            printf("Player 2 position is %d\n", cur_pos2);

            break;
        case '2':
            dice = rd();
            customSystem();
            printf("\t\t\t\tDice = %d\n\n", dice);
            cur_pos2 = dice + cur_pos2;
            if (cur_pos2 < 101)
            {
                if (cur_pos2 == 99) // snake
                {
                    displaychart(1, "$P2$");
                }
                if (cur_pos2 == 65) // snake
                {
                    displaychart(40, "$P2$");
                }
                if (cur_pos2 == 25) // snake
                {
                    displaychart(9, "$P2$");
                }
                if (cur_pos2 == 70) // ladder
                {
                    displaychart(93, "$P2$");
                }
                if (cur_pos2 == 60) // ladder
                {
                    displaychart(83, "$P2$");
                }
                if (cur_pos2 == 13) // ladder
                {
                    displaychart(42, "$P2$");
                }
                else
                {
                    displaychart(cur_pos2, "$P2$");
                }
            }

            else
            {
                cur_pos2 = cur_pos2 - dice;
                printf("Range exceeded of Player 2.\n");
                displaychart(cur_pos2, "$P2$");
            }
            printf("Player 1 position is %d\n", cur_pos1);
            break;
        case '3':
            exit(0);
            break;

        default:
            printf("Incorrect choice.Try Again\n");
        }
    }
}

// ------------------Tic-Tac-Toe----------------

// C program for creating & simulating a Snake & Ladder Game
// Constraints and Rules
/*
1.The game will begin with any dice value.
2.If a 6(six) is appeared then a chance is awarded to that player.
3.Only the location of current player is shown on the board,
    the location of other player is mentioned below the board.
4.Snakes:- 99 to  1, 65 to 40, 25 to 9.
5.Ladder:- 70 to 93, 60 to 83, 13 to 42.

*/

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void printBoard()
{
    customSystem();
    printf("\n\n");
    printf("=== TIC TAC TOE ===\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[7], board[8], board[9]);
    printf("     |     |     \n");
    printf("\n\n");
}

int checkWin()
{

    if (board[1] == board[2] && board[2] == board[3])
    {
        return 1;
    }
    if (board[1] == board[4] && board[4] == board[7])
    {
        return 1;
    }
    if (board[7] == board[8] && board[8] == board[9])
    {
        return 1;
    }
    if (board[3] == board[6] && board[6] == board[9])
    {
        return 1;
    }
    if (board[1] == board[5] && board[5] == board[9])
    {
        return 1;
    }
    if (board[3] == board[5] && board[5] == board[7])
    {
        return 1;
    }
    if (board[2] == board[5] && board[5] == board[8])
    {
        return 1;
    }
    if (board[4] == board[5] && board[5] == board[6])
    {
        return 1;
    }

    int count = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (board[i] == 'X' || board[i] == 'O')
        {
            count++;
        }
    }

    if (count == 9)
    {
        return 0;
    }
    return -1;
}

void ticTacToeMain()
{
    customSystem();
    int player = 1, input, status = -1;
    printBoard();

    while (status == -1)
    {
        player = (player % 2 == 0) ? 2 : 1;
        printf("Enter the value for player %d\n", player);
        char mark = (player == 1) ? 'X' : 'O';
        scanf("%d", &input);
        if (input < 1 || input > 9)
        {
            printf("Inavalid input");
        }
        board[input] = mark;
        printBoard();

        int result = checkWin();

        if (result == 1)
        {
            printf("Player %d is the Winner\n", player);
            return;
        }
        else if (result == 0)
        {
            printf("draw");
            return;
        }

        player++;
    }
}

int main()
{
    char ch;

    printf("Enter 's' to play Snake and Ladder Game OR \n\nEnter 't' to play TIC-TAC-TOE Game \n");
    scanf("%c", &ch);

    if (ch == 's' || ch == 'S')
    {
        snakeMain();
    }
    else if (ch == 'T' || ch == 't')
    {
        ticTacToeMain();
    }
    else
    {
        printf("Invalid Output\n");
    }

    return 0;
}
