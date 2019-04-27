#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void menu()
{
	printf("--------N子棋游戏-------\n");
	printf("---------1.play---------\n");
	printf("---------0.exit---------\n");
	printf("------------------------\n");
}
void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	InitBoard(board, ROW, COL);//初始化棋盘
	SetupBoard(board, ROW, COL);//建造棋盘
	while (1)
	{
		ComputerMove(board, ROW, COL);//电脑走
		ret = IsWin(board, ROW, COL);//判断输赢
		if (ret != ' ')
			break;
		SetupBoard(board, ROW, COL);
		PlayerMove(board, ROW, COL);//玩家走
		ret = IsWin(board, ROW, COL);//判断输赢
		if (ret != ' ')
			break;
		SetupBoard(board, ROW, COL);
	}
	if (ret == 'x')
	{
		printf("电脑赢！\n");
	}
	if (ret == '0')
	{
		printf("恭喜你赢了！\n");
	}
	else if (ret == 'T')
	{
		printf("平局！\n");
	}
}
int main()
{
	int put = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择(0或1)=>");
		scanf("%d", &put);
		switch (put)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("请输入0或1！输入错误，请重新输入！\n");
			break;
		}
	} while (put);
	return 0;
}
