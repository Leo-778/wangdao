/*
 * @Descripttion: 从递增的单链表A,B中，找公共元素，放在单链表c中,不破坏原结点
 * @Author: Leo
 * @Date: 2021-08-18 20:57:46
 * @LastEditTime: 2021-08-18 21:16:55
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

void get_same(LinkList A,LinkList B,LinkList &C){
    C->next =NULL;  //确认c为空链表；
    LNode *r;
    r = C; //初始化指针；
    
    if(A->next == NULL || B->next == NULL) return ;  //如果A或者B中存在空表；
    LNode *p = A->next;
    LNode *q = B->next;
    LinkList s;

    while(p!=NULL && q!= NULL){
        if(p->data > q->data){ //值比较小，则指针右移一位；
            q =q->next;
        }else if(p->data < q->data){
            p = p->next;
        }else{ //值相等；
            s=(LNode *)malloc(sizeof(LNode));  //创建*S结点；
            s->data = p->data;  //*S结点赋值；
            r->next = s;
            r = s;

            //A、B链表中剩余的元素继续比较；
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
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
    get_same(A, B, C);
    display(C);
    return 0;
}