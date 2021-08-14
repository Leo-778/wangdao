/*
 * @Descripttion: 有序表中删除所有重复的元素。
 * @Author: Leo
 * @Date: 2021-08-13 21:40:41
 * @LastEditTime: 2021-08-13 21:44:59
 */

#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10 //定义最大长度

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize]; //用静态的“数组”存放数据元素
    int length=0; //顺序表的当前长度
}SqList; //顺序表的类型定义（静态分配方式）


bool Del_same(SqList &l){
    int count = 0;
    for (int i = 1; i < l.length; i++)
    {
        if (l.data[i]!=l.data[i-1])
        {
            l.data[count] = l.data[i];
            count++;
        }
        
    }
    
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
    for (int i = 0; i < l.length; i++)
    {
        printf("%d,", l.data[i]);
    }
    return 0;
}