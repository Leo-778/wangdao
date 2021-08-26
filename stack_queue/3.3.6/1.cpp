/*
 * @Descripttion: 括号匹配
 * @Author: Leo
 * @Date: 2021-08-22 20:55:46
 * @LastEditTime: 2021-08-22 21:17:12
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

//括号匹配
bool bracketscheck(char *str){
    SqStack s;
    InitStack(s);
    ElemType e;
    int i = 0;
    while (str[i]!='\0')
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            Push(s, str[i]);
        }
        else{
            if (s.top==-1){
                printf("括号不匹配！");
                return false;
            }
            Pop(s, e);
            if (str[i] == '(' && e != ')'){
                printf("括号不匹配！");
                return false;
            }
            if (str[i] == '[' && e != ']'){
                printf("括号不匹配！");
                return false;
            }
            if (str[i] == '{' && e != '}'){
                printf("括号不匹配！");
                return false;
            }
        }
        i++;
    }
    if (s.top!=-1)
    {
        printf("括号不匹配！");
                return false;
    }
    printf("括号匹配！");
    return true;
}

int main(int argc, char const *argv[])
{
    char a[3] = {'(', '[','\0'};
    bracketscheck(a);
    return 0;
}
