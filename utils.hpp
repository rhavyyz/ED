#pragma once


int max(int a, int b)
{
    if(a > b) return a;
    return b;
}

int abs(int a)
{   
    if ( a > 0) return a;

    return -a;
}

template<typename T>
void swap(T &a, T &b)
{
    T aux = a;
    a = b;
    b = aux;
}