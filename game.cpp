#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define SIZE 20

extern int board[SIZE][SIZE];
stack path;

int victory(int x, int y, int color);
void draw();
void gaming(int color=1);
void save(char* filename);
void load(char* filename);
void welcome();

void run(int x, int y, int color);
void back(int color,int *succ);
void printHelp();

void StartNewGame()
{
    memset(board, 0, sizeof(board));
    path.init();
    draw();
    gaming();
}

void gaming(int color)
{
    int  x, y;
    char s[100], op;
    while (1)
    {
        printf("现在由%s方落子\n", color == 1 ? "黑" : "白");
       
        gets(s);
        if (s[0] == 'r')
        {
            sscanf(s, "%c %d %d", &op, &x, &y);
            if(x<0||x>=SIZE||y<0||y>=SIZE){
                printf("输入的坐标出界，请重新输入\n");
                continue;
            }
            if(board[x][y]!=0){
                printf("这个位置已经有棋子，请重新输入\n");
                continue;
            }
            run(x, y, color);
            if (color == 1)
                color = 2;
            else
                color = 1;
        }
        else if (s[0] == 'b')
        {
            int succ = 1;
            back(color,&succ);
            if (succ)
                if (color == 1)
                    color = 2;
                else
                    color = 1;
        }
        else if(s[0]=='s'){
            char filename[100];
            sscanf(s,"%c %s",&op,filename);
            save(filename);
            load(filename);
            printf("保存成功\n");
        }
        else if(s[0]=='l'){
            char filename[100];
            sscanf(s,"%c %s",&op,filename);
            load(filename);
            draw();
            printf("加载成功\n");
            if(path.top().state==1) color=2;
            else color=1;
        }
        else if(s[0]=='h') printHelp();
        else if(s[0]=='q') exit(1);
        else if(s[0]=='m') break;
        else{
            printf("没有这个命令，请重新输入\n");
            continue;
        }
    }
    if(s[0]=='m') welcome();
}

void run(int x, int y, int color)
{
    board[x][y] = color;
    draw();

    if (victory(x, y, color))
    {
        printf("%s方获胜\n按任意键回到主界面\n", color == 1 ? "黑" : "白");
        char op;
        scanf("%c", &op);
        welcome();
    }
    cell t = {x, y, color};
    path.push(t);
}

void back(int color, int *succ)
{
    if (path.empty())
    {
        printf("已经没有可悔的棋\n");
        *succ=0;
        return;
    }
    cell t = path.top();
    path.pop();
    board[t.x][t.y] = 0;
    draw();
    printf("%s方悔棋\n", color == 1 ? "白" : "黑");
}

void printHelp(){
printf("欢迎界面命令说明(括号中为参数):\n");
printf("n:开始新游戏\n");
printf("l (filename):从filename中加载未完成的棋局\n");
printf("q:退出\n\n");

printf("游戏时命令说明(括号中为参数):\n");
printf("r (rank) (column):在(rank,column)处落子\n");
printf("b:悔棋\n");
printf("s (filename):将棋局存在filename中\n");
printf("l (filename)：从filename中加载未完成的棋局\n");
printf("m：返回主菜单\n");
printf("q：退出\n\n");

printf("h:查看命令帮助\n\n");
}