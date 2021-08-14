/*
 * @Descripttion: 时间复杂度O(n),空间复杂度O(1),删除所有值为x的元素。
 * @Author: Leo
 * @Date: 2021-08-13 20:44:51
 */
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10 //定义最大长度

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize]; //用静态的“数组”存放数据元素
    int length=0; //顺序表的当前长度
}SqList; //顺序表的类型定义（静态分配方式）


bool Del_x(SqList &l,int x){
    int count=0;
    for (int i = 0; i < l.length; i++)
    {
        if (l.data[i]!=x)
        {
            l.data[count] = l.data[i];
            count++;
        }
    }
    l.length=count;
    return true;
}

int main(int argc, char const *argv[])
{
    SqList l;
    for (int i = 0; i < MaxSize; i++)
    {
        l.data[i] = 1 + i;
        l.length++;
    }
    l.data[5] = 4;
    Del_x(l, 4);
    for (int i = 0; i < l.length; i++)
    {
        printf("%d,", l.data[i]);
    }
    return 0;
}