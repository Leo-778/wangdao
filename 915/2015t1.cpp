/*
 * @Description: 二维数组的对角线之和
 * @Author: Leo
 * @Date: 2021-10-23 20:38:59
 * @LastEditTime: 2021-10-24 18:16:56
 */
#include<stdio.h>
int get_tr(int a[][3],int m,int n){//C语言二维数组必须指明列数
    if(m!=n)
        return false;
    int sum = 0;
    int i = 0;
    while (i<m)
    {
        if (i!=n-i-1)
        {
            sum = sum + a[i][i] + a[i][n - i-1];
            printf("%d\t%d\n", a[i][i], a[i][n - i - 1]);
        }
        if (i==n-i-1)
        {
            sum = sum + a[i][i];
            printf("%d\n", a[i][i]);
        }
        i++;
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    int t = 3;
    int a[3][3] = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
    int sum = get_tr(a,t,t);
    printf("%d", sum);
    return 0;
}
