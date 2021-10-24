/*
 * @Description: 删除单链表中，绝对值相等的结点，仅保留第一次出现的
 * @Author: Leo
 * @Date: 2021-08-19 18:53:43
 * @LastEditTime: 2021-08-19 19:05:55
 */

#include<stdio.h>
#include<math.h>
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

bool del_abs_same(LinkList &l,int n){
    LinkList p = l->next,r;
    int *q, m;
    q = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n+1; i++)
    {
        *(q + i) = 0;
    }
    
    while (p->next)
    {
        m = p->next->data > 0 ? p->next->data : -p->next->data;
        if (*(q+m)==0)
        {
            *(q + m) = 1;
            p = p->next;
        }
        else{
            r = p->next;
            p->next = r->next;
            free(r);
        }    
    }
    free(q);
    return true;
}


int main(int argc, char const *argv[])
{
    LinkList A;
    InitList(A);
    int a[6]={2,-3,4,-3,6,7};
    list_tailInsert(A, a, 6);
    display(A);
    del_abs_same(A, 10);
    display(A);
    return 0;
}