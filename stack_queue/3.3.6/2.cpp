/*
 * @Descripttion: 火车调度
 * @Author: Leo
 * @Date: 2021-08-22 21:18:07
 * @LastEditTime: 2021-08-26 20:39:11
 */
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

#define MaxSize 10 //定义队列中元素的最大个数
typedef struct 
{
    ElemType data[MaxSize];
    int top;
}SqStack;

//初始化栈
void InitStack(SqStack &S){
    S.top = -1; //初始化栈顶指针
}

//新元素入栈
bool Push(SqStack &S,ElemType x){
    if(S. top==MaxSize-1)//栈满， 报错
        return false;
    S.data[S.top] = x; //新元素入栈
    S.top = S.top + 1; //指针加一
    return true;
}

//出栈操作
bool Pop(SqStack &S, ElemType x){
    if(S. top==-1)//栈空，报错
        return false;
    x = S.data[S.top]; //栈顶元素先出栈"
    S.top = S.top - 1; //指针再减1.
    return true;
}

void train_arrange(char *train){
    SqStack s;
    InitStack(s);
    char *p = train, *q=train, c;
    while (*p)
    {
        if (*p=='H')
        {
            Push(s, *p);
        }
        else
            *(q++) = *p;
        p++;
    }
    while (s.top!=-1)
    {
        Pop(s, c);
        *(q++) = c;
    }
    return;
}
int main(int argc, char const *argv[])
{
    char a[10] = {'H', 's', 'H', 's', 'H', 's', 'H', 's', 'H', 's'};
    train_arrange(a);
    for (int i = 0; i < 10; i++)
    {
        printf("%c,", a[i]);
    }
    
    return 0;
}
