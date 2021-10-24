/*
 * @Description: 找出数组中没有出现的最小正整数
 * @Author: Leo
 * @Date: 2021-08-15 20:31:36
 * @LastEditTime: 2021-08-15 20:37:47
 */
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define MaxSize 100 //定义最大长度

int search_no_min(int *a,int n){
    int b[n + 1]={false};
    for (int i = 0; i < n; i++)
    {
        if (a[i]>0)
        {
            b[a[i]] = true;
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        if (!b[i])
        {
            return i;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int a[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    printf("%d\n", search_no_min(a,8));
    return 0;
}
