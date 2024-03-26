#include <stdio.h>
#include <time.h>

int done(char board[9][9])
{
    for (int i = 8; i >= 0; i--)
        for (int j = 8; j >= 0; j--)
            if (!board[i][j])
                return 0;
    return 1;
}

int poss(char board[9][9], int k, int a , int b)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[a][i] == k + 48)
            return 0;
        if (board[i][b] == k + 48)
            return 0;
    }

    int x = (a / 3) * 3;
    int y = (b / 3) * 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[x + i][y + j] == k + 48)
                return 0;

    return 1;
}

void print(char board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%c", board[i][j]);
            if (!((j + 1) % 3))
                printf("  ");
        }
        printf("\n");
        if (!((i + 1) % 3))
                printf("\n");
    }
    printf("\n");
}

int recur(char board[9][9], int a)
{
    if (done(board))
        return 1;

    for (int i = a; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (!board[i][j])
            {
                for (int k = 1; k <= 9; k++)
                    if (poss(board, k, i, j))
                    {
                        board[i][j] = k + 48;
                        if (recur(board, i))
                            return 1;
                        board[i][j] = 0;
                    }
                return 0;
            }
    return 0;
}

void solveSudoku(char board[9][9])
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] == '.')
                board[i][j] = 0;
    recur(board, 0);
}

int main(void)
{
	clock_t begin = clock();
	char board[9][9] = {{"5....637."},{".....3.84"},{"4........"},{"..92....3"},{".8.3.1.6."},{"3....95.."},{"........1"},{"84.9....."},{".528....7"}};
	solveSudoku(board);
	print(board);
	printf("%f\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
}
