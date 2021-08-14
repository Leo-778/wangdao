/*
 * @Descripttion: 将数组A[m+n]的前m和后n项置换（将1~m,1~n换为1~n,1~m）
 * @Author: Leo
 * @Date: 2021-08-14 20:34:25
 * @LastEditTime: 2021-08-14 21:07:25
 */
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define MaxSize 100 //定义最大长度

bool reserve(int *a, int left, int right)
{
    for (int i = 0; i <= (left+right)/2-left; i++)
    {
        swap(a[left + i], a[right - i]);
    }
    return true;
}

bool exchange(int *a,int m,int n,int len){
    reserve(a, 0, m-1);
    reserve(a, len-n, len-1);
    reserve(a, 0, len-1);
    return true;
}



int main(int argc, char const *argv[])
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    exchange(a, 4, 6, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    
    return 0;
}