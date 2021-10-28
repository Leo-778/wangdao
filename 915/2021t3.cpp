/*
 * @Description: 机器人繁殖
 * @Author: Leo
 * @Date: 2021-10-28 18:24:37
 * @LastEditTime: 2021-10-28 18:54:35
 */
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

#define maxsize 9999

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a=0, b=0, c=0, ma=1, add=0;//a是1天,b是2天,c是3天,ma是成熟,add总数
    for (int i = 2; i <= n; i++)
    {
        ma += c;
        c = b;
        b = a;
        a = ma;
        add = a + b + c + ma;
        printf("第%d天,a=%d,b=%d,c=%d,ma=%d,add=%d\n", i, a, b, c, ma, add);
    }
    cout << add;
    return 0;
}
