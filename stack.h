#pragma once

struct cell{
    int x,y,state;
    //x,y代表点的坐标
    //state为0代表没有旗子，1代表黑，2代表白
};
struct stack{
    cell s[410];
    cell *bottom,*rsp;
    void init();
    cell push(cell a);
    cell pop();
    cell top();
    int size();
    int empty();
    void clear();
};
