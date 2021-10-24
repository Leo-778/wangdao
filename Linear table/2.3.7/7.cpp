/*
 * @Description: 无序的单链表，删除给定[a,b]之间的值
 * @Author: Leo
 * @Date: 2021-08-17 20:17:30
 * @LastEditTime: 2021-08-17 20:26:49
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

void del_a_to_b(LinkList &l,int a,int b){
    LinkList pre = l, p = pre->next;
    while (p)
    {
        if (p->data>=a&&p->data<=b)
        {
            pre->next = p->next;
            p = pre->next;
        }
        else{
            p = p->next;
            pre = pre->next;
        }
    }
    
}

int main(int argc, char const *argv[])
{
    LinkList l;
    InitList(l);
    l = list_tailInsert(l);
    display(l);

    del_a_to_b(l, 5, 8);
    display(l);
    return 0;
}