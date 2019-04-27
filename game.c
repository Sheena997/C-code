#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void SetupBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走=>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'x';
			break;
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走=>\n");
	while (1)
	{
		printf("请输入坐标=>");
		scanf("%d%d", &x, &y);
		if (x >= 0 && x < row && y >= 0 && y <= col)
		{
			if (board[x][y] == ' ')
			{
				board[x][y] = '0';
				break;
			}
			else
			{
				printf("该坐标被占用，请重新输入！\n");
			}
		}
		else
		{
			printf("坐标不存在，请重新输入！\n");
		}
	}
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0; 
	int q = 0;
	char a[100] = { '0' };
	int count = 0;
	for (i = 0; i < row; i++)
	{
		count = 0;
		for (j = 0; j < col; j++)
		{
			a[j] = board[i][j];
		}
		for (q = 0; q <CH; q++)
		{
			if (a[q] == a[q + 1])
				count++;
			else
				break;
		}
		if (count == row-1)
		{
			return board[i][0];
		}
	}
	count = 0;
	for (j = 0; j < col; j++)
	{
		count = 0;
		for (i = 0; i < row; i++)
		{
			a[i] = board[i][j];
		}
		for (q = 0; q <CH; q++)
		{
			if (a[q] == a[q + 1])
				count++;
			else
				break;
		}
		if (count == (col-1))
		{
			return board[0][j];
		}
	}
	count = 0;
	for (i = 0; i < row; i++)
	{
		a[i] = board[i][i];
	}
	for (j = 0; j < col - 1; j++)
	{
		if (a[j] == a[j + 1])
		{
			count++;
		}
		else
			break;
	}
	if (count == (row - 1))
		return board[0][0];
	count = 0;
	for (i = 0; i < row; i++)
	{
		a[i] = board[i][row - 1 - i];
	}
	for (j = 0;j < col - 1; j++)
	{
		if (a[j] == a[j + 1])
		{
			count++;
		}
		else
			break;
	}
	if (count == (row - 1))
		return board[0][row - 1];
    if (IsFull(board, row, col))
	{
		return 'T';
	}
	else return ' ';
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}