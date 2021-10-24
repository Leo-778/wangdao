/*
 * @Description: 找出3个集合所有三元组的最小距离及相应的三元组
 * @Author: Leo
 * @Date: 2021-08-15 20:37:26
 * @LastEditTime: 2021-08-15 21:10:41
 */
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define MaxSize 100 //定义最大长度

int get_de(int a,int b,int c){
    return abs(a - b) + abs(b - c) + abs(a - c);
}

int search_de_min(int *a,int *b,int *c,int n,int m,int p){
    int x = 9999;
    int t ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                t = get_de(a[i], b[j], c[k]);
                if (t<x)
                {
                    x = t;
                }
            }
        }
    }
    return x;
}

int main(int argc, char const *argv[])
{
    int a[3] = {-1,0,9};
    int b[4] = {-25,-10,10,11};
    int c[5] = {2,9,17,30,41};
    printf("%d\n", search_de_min(a,b,c,3,4,5));
    return 0;
}
