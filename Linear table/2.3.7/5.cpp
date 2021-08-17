/*
 * @Descripttion: 将单链表就地逆置（空间复杂度为O(1)）
 * @Author: Leo
 * @Date: 2021-08-16 21:13:13
 * @LastEditTime: 2021-08-17 20:01:58
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

int a[maxsize] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//尾插法
LinkList list_tailInsert(LinkList &l){
    int x;
    l = (LinkList)malloc(sizeof(LNode));
    LinkList s, r = l;
    for (int i = 0; i < maxsize; i++)
    {
        x = a[i];
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
    }
    
    r->next = NULL;
    return l;
}

LinkList reserve(LinkList l){
    if (l->next==nullptr)
    {
        return l;
    }
    LinkList pre = l->next, p = pre->next, r = p->next;
    pre->next = nullptr;
    if(r==nullptr){
        p->next = pre;
        return p;
    }
    while (r!=nullptr)
    {
        p->next = pre;
        pre = p;
        p = r->next;
        r->next = pre;
        pre = r;
        r = p->next;
    }
    p->next = pre;
    l->next = p;
    return l;
}

int main(int argc, char const *argv[])
{
    LinkList l;
    InitList(l);
    l = list_tailInsert(l);
    display(l);

    l = reserve(l);
    display(l);
    return 0;
}