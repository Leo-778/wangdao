/*
 * @Descripttion: 找到两个等长的升序序列A,B的中位数(指两个序列的升序序列中间那个数)
 * @Author: Leo
 * @Date: 2021-08-14 21:29:28
 * @LastEditTime: 2021-08-15 20:09:10
 */
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define MaxSize 100 //定义最大长度

int search_mid(int *a,int *b,int n){
    int s1 = 0, d1 = n - 1, m1;
    int s2 = 0, d2 = n - 1, m2;
    while (s1!=d1 || s2!=d2)
    {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if(a[m1]==b[m2])
            return a[m1];
        if (a[m1]<b[m2])
        {
            if ((s1+d1)%2==1)
            {
                s1 = m1;
                d2 = m2;
            }
            else{
                s1 = m1 + 1;
                d2 = m2;
            }
        }
        else{
            if ((s1+d1)%2==1)
            {
                d1 = m1;
                s2 = m2;
            }
            else{
                d1 = m1 + 1;
                s2 = m2;
            }
        }
    }
    return a[s1] < b[s2] ? a[s1] : b[s2];
}
int main(int argc, char const *argv[])
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 51};
    int b[10] = {1, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    printf("%d\n", search_mid(a, b, 10));
    return 0;
}
