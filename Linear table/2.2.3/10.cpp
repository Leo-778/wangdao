/*
 * @Descripttion: 将一维数组n个元素循环左移p个位置
 * @Author: Leo
 * @Date: 2021-08-14 21:23:23
 * @LastEditTime: 2021-08-14 21:29:18
 */
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define MaxSize 100 //定义最大长度


bool reserve(int *a, int left, int right)
{
    for (int i = 0; i <= (left+right)/2-left; i++)
    {
        swap(a[left + i], a[right - i]);
    }
    return true;
}

void converse(int *a,int n,int p){
    reserve(a, 0, p-1);
    reserve(a, p, n-1);
    reserve(a, 0, n-1);
}


int main(int argc, char const *argv[])
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    converse(a, 10, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    
    return 0;
}