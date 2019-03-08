#pragma once
#define SIZE 20 

extern int board[SIZE][SIZE];

int victory(int x,int y,int color){
    int num=1;
    int tx,ty;
    
    tx=x;
    while(++tx<SIZE&&board[tx][y]==color) num++;
    tx=x;
    while(--tx>=0&&board[tx][y]==color) num++;
    if(num>=5) return 1;

    num=1,ty=y;
    while(++ty<SIZE&&board[x][ty]==color) num++;
    ty=y;
    while(--ty>=0&&board[x][ty]==color) num++;
    if(num>=5) return 1;

    num=1,tx=x,ty=y;
    while(++tx<SIZE&&++y<SIZE&&board[tx][ty]==color) num++;
    tx=x,ty=y;
    while(--tx>=0&&--ty>=0&&board[tx][ty]==color) num++;
    if(num>=5) return 1;

    num=1,tx=x,ty=y;
    while(++tx<SIZE&&--ty>=0&&board[tx][ty]==color) num++;
    tx=x,ty=y;
    while(--tx>=0&&++ty<SIZE&&board[tx][ty]==color) num++;
    if(num>=5) return 1;

    return 0;
}

