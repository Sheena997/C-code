#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void menu()
{
	printf("--------N������Ϸ-------\n");
	printf("---------1.play---------\n");
	printf("---------0.exit---------\n");
	printf("------------------------\n");
}
void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	InitBoard(board, ROW, COL);//��ʼ������
	SetupBoard(board, ROW, COL);//��������
	while (1)
	{
		ComputerMove(board, ROW, COL);//������
		ret = IsWin(board, ROW, COL);//�ж���Ӯ
		if (ret != ' ')
			break;
		SetupBoard(board, ROW, COL);
		PlayerMove(board, ROW, COL);//�����
		ret = IsWin(board, ROW, COL);//�ж���Ӯ
		if (ret != ' ')
			break;
		SetupBoard(board, ROW, COL);
	}
	if (ret == 'x')
	{
		printf("����Ӯ��\n");
	}
	if (ret == '0')
	{
		printf("��ϲ��Ӯ�ˣ�\n");
	}
	else if (ret == 'T')
	{
		printf("ƽ�֣�\n");
	}
}
int main()
{
	int put = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��(0��1)=>");
		scanf("%d", &put);
		switch (put)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("������0��1������������������룡\n");
			break;
		}
	} while (put);
	return 0;
}
