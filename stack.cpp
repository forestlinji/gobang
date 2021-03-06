#include <string.h>
#include "stack.h"


void stack::init()
{
    memset(s, 0, sizeof(s));
    bottom = rsp = &s[0];
}

void stack::push(cell a)
{
    *(rsp++) = a;
}

int stack::empty()
{
    return bottom == rsp;
}

cell stack::pop()
{
    cell t = {0, 0, 0};
    if (empty())
    {
        return t;
    }
    else
        return *(--rsp);
}

cell stack::top()
{
    cell t = {0, 0, 0};
    if (empty())
    {
        return t;
    }
    else
        return *(rsp-1);
}

int stack::size()
{
    return (rsp - bottom) / sizeof(cell);
}

void stack::clear()
{
    memset(s, 0, sizeof(s));
    bottom = rsp = &s[0];
}

