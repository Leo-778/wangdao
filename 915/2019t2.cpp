/*
 * @Description: 判断回文串
 * @Author: Leo
 * @Date: 2021-11-01 17:54:38
 * @LastEditTime: 2021-11-01 18:42:17
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int get_size(char *a){//获得字符长度
    int i = 0;
    while (a[i]!='\0')
        i++;
    return i;
}

// void shows(char *a){//打印字符，用于测试
//     for (int i = 0; i < get_size(a); i++)
//     {
//         cout << a[i];
//     }
//     cout << '\n';
// }



void del_space(char *a){//删除空格
    int i, j;
    for (i = 0, j = 0; i < get_size(a); )
    {
        if (a[i]!=' ')
        {
            a[j++] = a[i++];
        }
        else{
            i++;
        }
    }
    a[j] = '\0';
    return;
}

bool rec_hui(char *a,int start,int end){
    if(start==end||start>end){
        return 1;
    }
    else{
        return a[start] == a[end-1] ? rec_hui(a, start + 1, end - 1) : 0;
    }
}

bool norec_hui(char *a){
    int i = get_size(a);
    for (int j = 0; j < i; j++)
    {
        if (a[j]!=a[i-1])
            return false;
        i--;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    char a[100];
    gets(a);
    del_space(a);
    int i = get_size(a);
    if (rec_hui(a,0,i))
        cout << "是回文串";
    else
        cout << "不是回文串";
    return 0;
}