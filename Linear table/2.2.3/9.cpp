/*
 * @Description: 有序表找到x，并与后继元素交换，找不到，插入，仍有序。
 * @Author: Leo
 * @Date: 2021-08-14 21:07:43
 * @LastEditTime: 2021-08-14 21:23:13
 */

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define MaxSize 100 //定义最大长度

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize]; //用静态的“数组”存放数据元素
    int length=0; //顺序表的当前长度
}SqList; //顺序表的类型定义（静态分配方式）


bool find_x(SqList &l,int x){
    int i;
    for (i = 0; i < l.length; i++)
    {
        if (l.data[i]==x)
        {
            swap(l.data[i], l.data[i + 1]);
            return true;
        }
        if (l.data[i]<x&&l.data[i+1]>x)
        {
            break;
        }
    }
    for (int j = l.length; j>i+1 ; j--)
    {
        l.data[j] = l.data[j - 1];
    }
    l.data[i + 1] = x;
    l.length++;
    return true;
}

void init(SqList &l,int x){
    for (int i = 0; i < 10; i++)
    {
        l.data[i] = x + i*i;
        l.length++;
    }
}

void print(SqList l){
    for (int i = 0; i < l.length; i++)
    {
        printf("%d ", l.data[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    SqList l;
    init(l,1);
    print(l);
    find_x(l, 17);
    print(l);
}