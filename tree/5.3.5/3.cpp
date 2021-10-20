/*
 * @Descripttion: 后序遍历非递归初始化两个栈，一个栈用来回溯结点，一个栈用来输出
 * @Author: Leo
 * @Date: 2021-08-30 20:21:43
 * @LastEditTime: 2021-08-30 20:44:37
 */
#include <stdio.h>
#define MaxSize 100
 
//二叉树的结点（链式存储）
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,* BiTree;

//定义栈
typedef struct{
    BiTree data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &S);
bool StackIsEmpty(SqStack &S);
bool Push(SqStack &S, BiTree x);
bool Pop(SqStack &S, BiTree &x);
void visit(BiTree T);


void post(BiTree t){
    BiTree p = t;
    SqStack s1, s2;
    InitStack(s1);
    InitStack(s2);
    while (p||!StackIsEmpty(s1))
    {
        while (p)
        {
            Push(s1, p);
            Push(s2, p);
            p = p->lchild;
        }
        if(!StackIsEmpty(s1))
        {
            Pop(s1, p);
            p = p->rchild;
        }
    }
    while (!StackIsEmpty(s2))
    {
        Pop(s2, p);
        visit(p);
    }
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
