/*
 * @Description: 栈模拟队列
 * @Author: Leo
 * @Date: 2021-08-21 21:05:21
 * @LastEditTime: 2021-08-21 21:31:45
 */

#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

#define MaxSize 10 //定义队列中元素的最大个数
typedef struct{
    ElemType data[MaxSize];
    int front, rear; //队头指针和队尾指针
    int size=0;
} SqQueue;

typedef struct 
{
    ElemType data[MaxSize];
    int top;
}SqStack;

//栈的基本操作
//初始化栈
void InitStack(SqStack &S){
    S.top = -1; //初始化栈顶指针
}

//判断栈空
bool isEmpty(SqStack S){
    if(S. top==-1)//栈空
        return true;
    else          //不空
        return false;
}

//判断栈满
bool isFull(SqStack S){
    if(S. top==MaxSize-1)//栈满
        return true;
    else          //不空
        return false;
}

//新元素入栈
bool Push(SqStack &S,ElemType x){
    if(S. top==MaxSize-1)//栈满， 报错
        return false;
    S.top = S.top + 1; //指针先加一
    S.data[S.top] = x; //新元素入栈
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

//获取栈顶元素
bool GetTop(SqStack S, ElemType &x){
    if(S. top==-1)//栈空， 报错
        return false;
    x=S. data[S.top];//x记录栈顶元素
    return true;
}
//出队
bool DeQueue(SqStack &s1,SqStack &s2,ElemType &x){
    if (!isEmpty(s2))
    {
        Pop(s2, x);
        return true;
    }
    if (isEmpty(s2)&&!isEmpty(s1))
    {
        while (!isEmpty(s1))
        {
            Pop(s1, x);
            Push(s2, x);
        }
        Pop(s2, x);
        return true;
    }
    if (isEmpty(s2)&&isEmpty(s1))
    {
        return false;
    }
    return true;
}
//入队
bool EnQueue(SqStack &s1,SqStack &s2,ElemType x){
    if (!isFull(s1))
    {
        Push(s1, x);
        return true;
    }
    if (isFull(s1)&&isEmpty(s2))
    {
        while (!isEmpty(s1))
        {
            Push(s1, x);
            Pop(s2, x);
        }
        Push(s1, x);
        return true;
    }
    if (isFull(s2)&&!isEmpty(s1))
    {
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
