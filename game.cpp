
#include <string.h>
#include <stdio.h>
#include "stack.h"
#include "error.h"
//#include "draw.cpp"
//#include "victory.cpp"
#define SIZE 20

int victory(int x, int y, int color);
void draw();
void gaming();
void save(char* filename);
void load(char* filename);
extern int board[SIZE][SIZE];
stack path;

void run(int x, int y, int color);
void back(int color,int *succ);

void StartNewGame()
{
    memset(board, 0, sizeof(board));
    path.init();
    draw();
    gaming();
}

void gaming()
{
    int color = 1, x, y;
    while (1)
    {
        printf("现在由%s方落子\n", color == 1 ? "黑" : "白");
        //scanf("%c", &op);
        char s[100], op;
        gets(s);
        if (0)
            OPERATE_ERROR();
        if (s[0] == 'r')
        {
            sscanf(s, "%c %d %d", &op, &x, &y);
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
            //printf("%s\n\n",filename);
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
    }
}

void run(int x, int y, int color)
{

    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
        OUT_OF_RANGE();
    if (board[x][y] != 0)
        OCCUPIED();
    board[x][y] = color;
    draw();

    if (victory(x, y, color))
    {
        printf("%s方获胜\n按任意键继续\n", color == 1 ? "黑" : "白");
        char op;
        scanf("%c", &op);
        return;
    }
    cell t = {x, y, color};
    path.push(t);
}

void back(int color, int *succ)
{
    if (path.empty())
    {
        printf("已经没有可毁的棋\n");
        *succ=0;
        return;
    }
    cell t = path.top();
    path.pop();
    board[t.x][t.y] = 0;
    draw();
    printf("%s方悔棋\n", color == 1 ? "白" : "黑");
}
