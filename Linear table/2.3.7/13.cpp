/*
 * @Description: 将两个递增单链表归并为一个递减的单链表，并用原来的节点保存
 * @Author: Leo
 * @Date: 2021-08-17 21:30:10
 * @LastEditTime: 2021-08-18 20:57:07
 */

#include<stdio.h>
#include<stdlib.h>
//建立单链表(头插法，尾插法)
typedef int ElemType;
#define maxsize 10

typedef struct LNode               //定义单链表结点类型
{
    ElemType data;                //每个节，点存放一个数据元素
    struct LNode *next;           //指针指向下一个节点
} LNode, *LinkList;

bool InitList(LinkList &l){
    l = (LNode *)malloc(sizeof(LNode));//分配头结点
    if (l==NULL)       //内存不足，分配失败
        return false;
    l->next = NULL;    //头结点之后暂时还没有节点
    return true;
}

void display(LinkList p) {
    LinkList temp = p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next) {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}


//尾插法
void list_tailInsert(LinkList &l,int *a,int n){
    int x;
    l = (LinkList)malloc(sizeof(LNode));
    LinkList s, r = l;
    for (int i = 0; i < n; i++)
    {
        x = a[i];
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
    }
    
    r->next = NULL;
    return ;
}
bool ListMerge(LinkList &A,LinkList &B)
{
    LinkList p,q,t;
    p=A->next;
    q=B->next;
    A->next=NULL;
    delete B;
    while(p&&q)
    {
        if(p->data<=q->data)
        {
            t=p;
            p=p->next;
            t->next=A->next;
            A->next=t;                      
        }
        else
        {
            t=q;
            q=q->next;
            t->next=A->next;
            A->next=t;          
        }  
    }
    while(p)
    {
        t=p;
        p=p->next;
        t->next=A->next;
        A->next=t;
    }
    while(q)
    {
        t=q;
        q=q->next;
        t->next=A->next;
        A->next=t;
    }
    return true;
}


int main(int argc, char const *argv[])
{
    LinkList A,B;
    InitList(A);
    InitList(B);
    int a[4]={1,2,2,3};
    int b[6]={2,3,4,5,6,7};
    list_tailInsert(A,a,4);
    list_tailInsert(B, b, 6);
    ListMerge(A, B);
    display(A);
    return 0;
}