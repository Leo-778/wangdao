/*
 * @Description: 将顺序表所有元素逆置
 * @Author: Leo
 * @Date: 2021-08-13 20:38:34
 */
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define MaxSize 10 //定义最大长度

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize]; //用静态的“数组”存放数据元素
    int length=0; //顺序表的当前长度
}SqList; //顺序表的类型定义（静态分配方式）


bool reserve(SqList &l){
    for (int i = 0; i < l.length/2; i++)
    {
        swap(l.data[i], l.data[l.length - 1 - i]);
    }
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
    reserve(l);
    for (int i = 0; i < l.length; i++)
    {
        printf("%d,", l.data[i]);
    }
    
    return 0;
}
