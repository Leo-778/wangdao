/*
 * @Description: 覆盖所有点坐标
 * @Author: Leo
 * @Date: 2021-10-31 18:15:02
 * @LastEditTime: 2021-10-31 18:42:30
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[100], b[100];
    int x, y,i=0;
    while (1)
    {
        cin >> x>> y;
        if (x==0&&y==0)
            break;
        else{
            a[i] = x;
            b[i] = y;
            i++;
        }
    }
    cout << "start:" << '\n';
    for (int j = 0; j < i; j++)
        cout << a[j] << ' ';
    cout << '\n';
    for (int j = 0; j < i; j++)
        cout << b[j] << ' ';
    cout << '\n';
    sort(a, a + i);
    sort(b, b + i);
    cout << "after:" << '\n';
    for (int j = 0; j < i; j++)
        cout << a[j] << ' ';
    cout << '\n';
    for (int j = 0; j < i; j++)
        cout << b[j] << ' ';
    cout << '\n';
    printf("右上角：(%d,%d)\n", a[i-1], b[i-1]);
    printf("左上角：(%d,%d)\n", a[0], b[0]);
    return 0;
}