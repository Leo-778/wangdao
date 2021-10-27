/*
 * @Description: 寻找马鞍点
 * @Author: Leo
 * @Date: 2021-10-26 19:13:46
 * @LastEditTime: 2021-10-27 06:44:00
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[100][100];
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    int count = 0, b[100], c[100];//b是每行最小的数，c是每列最大的数
    for (int i = 0; i < n; i++)//找到每列最大的数
    {
        int mx = 0;
        for (int j = 0; j < m; j++)
        {
            mx > a[j][i] ?: mx = a[j][i];
        }
        c[i] = mx;
    }
    for (int i = 0; i < m; i++)//找到每行最大的数
    {
        int mn = 9999;
        for (int j = 0; j < n; j++)
        {
            mn < a[i][j] ?: mn = a[i][j];
        }
        b[i] = mn;
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j]==b[i]&&a[i][j]==c[j])
            {
                printf("%d %d %d\n", i, j, a[i][j]);
                count = 1;
            }
        }
    }
    if (count==0)
    {
        cout << "no exit";
    }
    return 0;
}
