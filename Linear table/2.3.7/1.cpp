/*
 * @Description: 删除不带头结点的单链表l中所有值为x的元素(递归实现)
 * @Author: Leo
 * @Date: 2021-08-15 21:11:35
 * @LastEditTime: 2021-10-20 21:02:01
 */
#include<stdio.h>
#include<stdlib.h>
//建立单链表(头插法，尾插法)
typedef int ElemType;

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
int a[10] = {3,6,3,3,3,9,3,4,3,1};
//尾插法
LinkList list_tailInsert(LinkList &l){
    int x;
    l = (LinkList)malloc(sizeof(LNode));
    LinkList s, r = l;
    for (int i = 0; i < 10; i++)
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
void display(LinkList p) {
    LinkList temp = p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next) {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}

void del_x(LinkList &l,int x){
    LinkList p;
    if (l==nullptr)
        return;
    if (l->data==x)
    {
        p = l;
        l = l->next;
        free(p);
        del_x(l, x);
    }
    else{
        del_x(l->next, x);
    }
}

void Del_x(LinkList &l,int x){//错误的写法
    LinkList p = l->next;
    if (l->next==nullptr)
    {
        return;
    }
    if (l->next->data==x)
    {
        l->next = p->next;
        free(p);
    }
    return Del_x(l->next, x);
}

int main(int argc, char const *argv[])
{
    LinkList l;
    InitList(l);
    l = list_tailInsert(l);
    display(l);
    Del_x(l, 3);
    display(l);
    return 0;
}