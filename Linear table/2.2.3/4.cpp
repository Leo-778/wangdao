/*
 * @Descripttion: 在有序顺序表中删除[s,t]之间的元素
 * @Author: Leo
 * @Date: 2021-08-13 21:10:29
 * @LastEditTime: 2021-08-13 21:35:20
 */
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10 //定义最大长度

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize]; //用静态的“数组”存放数据元素
    int length=0; //顺序表的当前长度
}SqList; //顺序表的类型定义（静态分配方式）


bool Del_st(SqList &l,int s,int t){
    int i, j;
    if (s>=t || l.length==0)
        return false;
    for (i = 0; i < l.length && l.data[i] < s;i++);
    if(i>=l.length)
        return false;
    for (j = i; j < l.length && l.data[j] <= t; j++);
    for (; j < l.length;i++,j++)
        l.data[i] = l.data[j];
    l.length = i;
    return true;
}

int main(int argc, char const *argv[])
{
    SqList l;
    for (int i = 0; i < MaxSize; i++)
    {
        l.data[i] = 1 + i*i;
        l.length++;
    }
    for (int i = 0; i < l.length; i++)
    {
        printf("%d,", l.data[i]);
    }
    printf("\n");
    Del_st(l, 1,45);
    for (int i = 0; i < l.length; i++)
    {
        printf("%d,", l.data[i]);
    }
    return 0;
}