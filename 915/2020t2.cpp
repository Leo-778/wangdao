/*
 * @Description: 输出两个数的和等于其反序数的和
 * @Author: Leo
 * @Date: 2021-10-29 18:54:35
 * @LastEditTime: 2021-10-29 19:20:58
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int fanxushu(int x){//获得反序数
    int a=0;
    while (x!=0)
    {
        a = a * 10 + x % 10;
        x = x / 10;
    }
    return a;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    printf("满足条件的有：\n");
    for (int i = 0; i < n; i++)
    {
        if (fanxushu(a[i]+b[i])==fanxushu(a[i])+fanxushu(b[i]))
            printf("a=%d,b=%d\n", a[i], b[i]);
    }

    //测试fanxushu()
    // cout << fanxushu(2352);
    return 0;
}
