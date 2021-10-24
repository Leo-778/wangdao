/*
 * @Description: 删除最小值元素，并返回被删除元素值。空出位置由后面补
 * @Author: Leo
 * @Date: 2021-08-13 20:17:44
 */
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10 //定义最大长度

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize]; //用静态的“数组”存放数据元素
    int length=0; //顺序表的当前长度
}SqList; //顺序表的类型定义（静态分配方式）


bool Del_min(SqList &l,int &x){
    int t = 9999, tag = 0;
    for (int i = 0; i < l.length; i++)
    {
        if (l.data[i]<t)
        {
            t = l.data[i];
            tag = i;
        }
    }
    x = l.data[tag];
    l.data[tag] = l.data[l.length - 1];
    l.length--;
    return true;
}

int main(int argc, char const *argv[])
{
    SqList l;
    int x;
    for (int i = 0; i < MaxSize; i++)
    {
        l.data[i] = 12 + i;
        l.length++;
    }
    l.data[5] = 4;
    Del_min(l, x);
    printf("%d\n", x);
    return 0;
}
