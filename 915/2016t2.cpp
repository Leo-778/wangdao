/*
 * @Description: 统计一个数字上，个位置等于n的数字数目
 * @Author: Leo
 * @Date: 2021-10-24 18:34:41
 * @LastEditTime: 2021-10-24 18:47:54
 */
#include<stdio.h>
#include<algorithm>
using namespace std;

typedef int TT;

int get_eqn(TT a,int n){
    TT t,count=0;
    if (n<0||n>9)
    {
        return -1;
    }
    while (a!=0)
    {
        t = a % 10;
        if (t==n)
        {
            count++;
        }
        a = a / 10;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    TT m = 6666;
    int count = get_eqn(m, 6);
    printf("%d\n", count);
    return 0;
}
