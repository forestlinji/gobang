#include <stdio.h>
#include <windows.h>
#define SIZE 20
extern int board[SIZE][SIZE];

char chess(int i,int j){
	if(board[i][j]==0) return ' ';
	else if(board[i][j]==1) return 'O';
	else return 'X';
}
//打印棋盘 
void draw()
{
	int i = 0;
	int j = 0;
	system("cls"); //清空屏幕 
	for (i = 0; i < 20; i++)
	{
		printf(" %2d ", i); //打印棋盘 x 轴坐标提示
	}
	printf("\n");
 
	for (j = 0; j < 20; j++)
	{
		printf("---|"); //打印第一行棋盘
	}
	printf("\n");
 
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			printf(" %c |", chess(i,j)); //打印竖标
		}
		printf(" %d ", i); //打印棋盘 y 轴坐标提示
		printf("\n");
 
		for (j = 0; j < 20; j++)
		{
			printf("---|"); //打印横标
		}
		printf("\n");
	}
}
