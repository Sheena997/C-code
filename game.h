#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 5
#define COL 5
#define CH 5

void InitBoard(char board[ROW][COL], int row, int col);
void SetupBoard(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
int IsFull(char board[ROW][COL], int row, int col);