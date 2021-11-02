/*
 * @Description: 逆序对
 * @Author: Leo
 * @Date: 2021-11-02 18:39:20
 * @LastEditTime: 2021-11-02 18:45:40
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, count = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[i]>a[j])
            {
                count++;
                printf("(%d,%d)\n", a[i], a[j]);
            }
        }
    }
    cout << count;
    return 0;
}
