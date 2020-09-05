#include <stdio.h>
#include "conio.h"  // Scanf Keyboard
#define SZ 39
char Board[SZ][SZ];

void InitBoard();
void PrintBoard();
int main()
{
    InitBoard();
    PrintBoard();

    char c;
    while (kbhit() == 0)
        PrintBoard();
    c = getch();

    printf("%c", c);

    return 0;
}

void PrintBoard()
{
    int i, j;
    for (i = 0; i < SZ; i++)
    {
        for (j = 0; j < SZ; j++)
            printf("%c", Board[i][j]);
        printf("\n");
    }
}

void InitBoard()
{
    int i, j;
    Board[0][0] = 1;
    Board[0][SZ - 1] = 2;
    Board[SZ - 1][0] = 3;
    Board[SZ - 1][SZ - 1] = 4;

    for (i = 0; i < SZ; i++)
        for (j = 0; j < SZ; j++)
        {
            if (i % 38 == 0 && j % 38 == 0)
                continue;
            else if (i % 2 == 1 && j % 2 == 0)
                Board[i][j] = 5;
            else if (i % 2 == 0 && j % 2 == 1)
                Board[i][j] = 6;
            else if (i % 2 == 0 && j % 2 == 0)
            {
                if (i == 0)
                    Board[i][j] = 22;
                else if (i == 38)
                    Board[i][j] = 21;
                else if (j == 0)
                    Board[i][j] = 25;
                else if (j == 38)
                    Board[i][j] = 23;
                else
                    Board[i][j] = 16;
            }
        }
}
