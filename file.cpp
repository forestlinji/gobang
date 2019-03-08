#define SIZE 20
#import "error.h"
#import "stack.h"
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
extern int board[SIZE][SIZE];
extern stack path;
void save(char* filename)
{
    
    FILE* file=fopen(filename,"w");
    while(!path.empty()){
        cell temp=path.top();
        path.pop();
        fprintf(file,"%d %d %d\n",temp.x,temp.y,temp.state);
    }
    fclose(file);

}

void load(char* filename)
{
    FILE *file = fopen(filename, "r");
    path.clear();
    stack t;
    t.init();
    cell temp;
    memset(board,0,sizeof(board));
    while (fscanf(file, "%d %d %d", &temp.x, &temp.y, &temp.state)!=EOF)
    {
        t.push(temp);
    }
    while (!t.empty())
    {
        temp=t.top();
        board[temp.x][temp.y]=temp.state;
        path.push(temp);
        t.pop();
    }
    fclose(file);

}