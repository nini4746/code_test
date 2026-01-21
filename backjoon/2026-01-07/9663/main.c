// 백준 9663번: N×N 체스판에 서로 공격하지 않게 퀸 N개 놓기

#include <stdio.h>
#include <stdlib.h>

int check(int *board, int size, int row)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == board[row])
            return (0);
        if (abs(board[i] - board[row]) == abs(i - row))
            return (0);
    }
    return (1);
}

int run(int *board, int size, int row)
{
    if (row == size)
        return 1;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        board[row] = i + 1;
        if (!check(board, size, row))
        {
            board[row] = -1;
            continue;
        }
        sum += run(board, size, row + 1);
    }
    return sum;
}


int main(void)
{
    int n;

    scanf("%d", &n);

    int *board = calloc(n, sizeof(int));
    int cnt = run(board, n, 0);
    
    printf("%d", cnt);
}
