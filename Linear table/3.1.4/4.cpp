/*
 * @Descripttion: 判断单链表是否中心对称
 * @Author: Leo
 * @Date: 2021-08-20 21:04:43
 * @LastEditTime: 2021-08-20 21:10:31
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
void list_tailInsert(LinkList &l,ElemType *a,ElemType n){
    ElemType x;
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

int dc(LinkList L, int n){
    LinkList p;
    //h是带头结点的n个元素单链表，本算法判断链表是否是中心对称
    int s[n/2];int i=1;  //i记结点个数，s字符栈
    p=L->next;  //p是链表的工作指针，指向待处理的当前元素
    for(i=0;i<n/2;i++) {  //链表前一半元素进栈
        s[i]=p->data;
        p=p->next;
    }
    i--;  //恢复最后的i值
    if(n%2==1)  //若n是奇数，后移过中心结点
        p=p->next;

    while(p!=NULL && s[i] ==p->data) { //检测是否中心对称
        i--;  //i充当找顶指针
        p=p->next;
    }

    if (i==-1)    //桟为空找
        return 1;    //链表中心对称
    else
        return 0;    //链表不中心对称
}



int main(int argc, char const *argv[])
{
    LinkList A;
    InitList(A);
    ElemType a[6]={2,-3,4,4,-3,2};
    list_tailInsert(A, a, 6);
    display(A);
    printf("%d\n", dc(A, 6));
    return 0;
}