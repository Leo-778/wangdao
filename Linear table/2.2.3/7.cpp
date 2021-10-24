/*
 * @Description: 将两个有序顺序表合并成新的有序顺序表(从小到大)
 * @Author: Leo
 * @Date: 2021-08-14 20:07:47
 * @LastEditTime: 2021-08-14 20:34:13
 */
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100 //定义最大长度

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize]; //用静态的“数组”存放数据元素
    int length=0; //顺序表的当前长度
}SqList; //顺序表的类型定义（静态分配方式）


bool merge(SqList l,SqList t,SqList &k){
    int i = 0, j = 0, m = 0;
    while (i < l.length && j < t.length)
    {
        if (l.data[i]<=t.data[j])
        {
            k.data[m] = l.data[i];
            i++;m++;
        }
        else{
            k.data[m] = t.data[j];
            j++;m++;
        }
    }
    while (j<t.length)
    {
        k.data[m] = t.data[j];
        j++;m++;
    }
    while (i<l.length)
    {
        k.data[m++] = l.data[i++];
    }
    k.length = m;
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
    SqList l,t,k;
    init(l,1);
    init(t,3);
    print(l);
    print(t);
    merge(l, t, k);
    print(k);
    return 0;
}