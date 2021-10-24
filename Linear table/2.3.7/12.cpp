/*
 * @Description: 去除单链表中重复元素{7,7,8,8}->{7,8}
 * @Author: Leo
 * @Date: 2021-08-17 21:15:04
 * @LastEditTime: 2021-08-17 21:31:40
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

int a[maxsize] = {9, 8, 8, 6, 6, 3, 3, 1, 1, 0};
//尾插法
void list_tailInsert(LinkList &l){
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
    return ;
}

void del_same(LinkList &a){
    LinkList p = a->next, q;
    if(p==nullptr)
        return;
    while (p->next)
    {
        q = p->next;
        if (p->data==q->data)
        {
            p->next = q->next;
            free(q);
        }
        else
        {
            p = p->next;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    LinkList a;
    InitList(a);
    list_tailInsert(a);
    display(a);
    del_same(a);
    display(a);
    return 0;
}