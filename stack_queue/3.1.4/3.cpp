/*
 * @Descripttion: 判断所给入栈出栈序列是否合法（1表示入栈,0表示出栈）
 * @Author: Leo
 * @Date: 2021-08-20 20:07:36
 * @LastEditTime: 2021-08-20 21:04:26
 */
#include<stdio.h>

bool isleg(int *a,int n){
    int cont=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1){
            cont++;
        }
        if (a[i]==0)
        {
            cont--;
            if (cont<0)
                return false;
        }
    }
    if (cont==0)
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    int a[8] = {1, 1, 1, 0, 0, 1, 0, 0};
    printf("%d", isleg(a, 8));
    return 0;
}
