/*
 * @Description: 判断是否是完美数
 * @Author: Leo
 * @Date: 2021-10-27 06:49:11
 * @LastEditTime: 2021-10-27 18:51:24
 */
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
#define N 10000

bool iszhi(int x){
    for (int i = 2; i < x/2+1; i++)
    {
        if (x%i==0)
        {
            return false;
        }
        
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int x,i=0,s,k=0,p=1;
    int a[N] = {};//a[]用来存放1~N的完全数
    for (x = 1; x < N; x++)//找到完全数
    {
        s = 0;
        for (int j = 1; j < x/2+1; j++){
            if (x%j==0)
                s += j;
        }
        if (s==x){
            a[k++] = x;
        }
    }
    // for (int i = 0; i < k; i++)//测试
    //     cout << a[i] << '\n';
    for ( i = 0; i < k; i++)
    {
        while ((pow(2,p)-1)*pow(2,p-1)<a[i])
            p++;
        cout << a[i] << ' ' << p << '\n';
    }
    return 0;
}
