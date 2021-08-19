/*
 * @Descripttion: 递增的单链表A,B;求交集,放在A中
 * @Author: Leo
 * @Date: 2021-08-18 21:13:13
 * @LastEditTime: 2021-08-18 21:19:13
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

void get_same(LinkList &A,LinkList &B){
    LinkList pa, pb, pc, u;
    pa=A->next;  //设工作指针分别为pa和pb
    pb=B->next;
    pc=A;  //结果表中当前合并结点的前驱指针
    while(pa&&pb){
        if(pa->data==pb->data) {  //交集并入结果表中
            pc->next=pa;    //A中结点链接到结果表
            pc=pa;
            pa=pa->next;
            u=pb;  //B中结点释放
            pb=pb->next;
            free(u);
        }
        else if (pa->data<pb->data) { //若A中当前结点值小于B中当前结点值
            u=pa;
            pa=pa->next;  //后移指针
            free(u) ; //释放A中当前结点
        }else{  //若B中当前结点值小于A中当前结点值
            u=pb;
            pb=pb->next;  //后移指针
            free (u) ;  //释放B中当前结点
        }
    }  //while 结束
    while(pa){    //B已遍历完，A未完
        u=pa;
        pa=pa->next;
        free (u) ;  //释放A中剩余结点
    }
    while(pb){  //A已遍历完，B未完
        u=pb;
        pb=pb->next;
        free(u) ; //释放B中剩余结点
    }
    pc->next=NULL;    //置结果链表尾指针为NULL
    free (B) ;    //释放B表的头结点
}


int main(int argc, char const *argv[])
{
    LinkList A,B,C;
    InitList(A);
    InitList(B);
    InitList(C);
    int a[4]={1,2,3,7};
    int b[6]={2,3,4,5,6,7};
    list_tailInsert(A, a, 4);
    list_tailInsert(B, b, 6);
    get_same(A, B);
    display(A);
    return 0;
}