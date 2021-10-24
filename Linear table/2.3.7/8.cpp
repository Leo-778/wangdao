/*
 * @Description: 找出两个单链表的公共结点
 * @Author: Leo
 * @Date: 2021-08-17 20:27:02
 * @LastEditTime: 2021-08-17 20:49:36
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

int ax[maxsize] = {8, 7, 9, 5, 4, 3, 2, 1, 0, 6};
//尾插法
LinkList list_tailInsert(LinkList &l){
    int x;
    l = (LinkList)malloc(sizeof(LNode));
    LinkList s, r = l;
    for (int i = 0; i < maxsize; i++)
    {
        x = ax[i];
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
    }
    
    r->next = NULL;
    return l;
}

//时间复杂度是O(n*n)
LinkList find_same(LinkList l,LinkList p){
    LinkList m=l->next, n=p->next;
    while (m)
    {
        while (n)
        {
            if (m!=n)
            {
                n = n->next;
            }
            else{
                return n;
            }
        }
        n = p->next;
        m = m->next;
    }
    return NULL;
}

//时间复杂度O(n)
LinkList find_same2(LinkList l, LinkList p){
    int x=0, y=0;
    LinkList n=l->next, m=p->next;
    while (n)
    {
        n = n->next;
        x++;
    }
    while (m)
    {
        m = m->next;
        y++;
    }
    n=l->next, m=p->next;
    int cnt = x-y;
    if (cnt>0)
    {
        for (int i = 0; i < cnt; i++)
        {
            n = n->next;
        }
    }
    else{
        for (int i = 0; i < -cnt; i++)
        {
            m = m->next;
        }
    }
    while (n)
    {
        if (n==m)
        {
            return n;
        }
        n = n->next;
        m = m->next;
    }
    return nullptr;
}

    int main(int argc, char const *argv[])
{
    LinkList l,p;
    InitList(l);
    InitList(p);
    l = list_tailInsert(l);
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = 9999;
    s->next = p->next;
    p->next = s;
    p->next->next = l->next->next->next->next;
    display(l);
    display(p);

    printf("%d", find_same2(l, p)->data);
    return 0;
}