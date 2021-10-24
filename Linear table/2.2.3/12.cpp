/*
 * @Description: 找出主元素
 * @Author: Leo
 * @Date: 2021-08-15 20:09:45
 * @LastEditTime: 2021-08-15 20:31:29
 */
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define MaxSize 100 //定义最大长度

int search_maj(int *a,int n){
    int b[n]={0},m=0,t=0;
    for (int i = 0; i < n; i++)
    {
        b[a[i]] = b[a[i]] + 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i]>m)
        {
            m = b[i];
            t = i;
        }
    }
    if (m>n/2)
    {
        return t;
    }else{
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    int a[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    printf("%d\n", search_maj(a,8));
    return 0;
}
