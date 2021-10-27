/*
 * @Description: 判断回文串
 * @Author: Leo
 * @Date: 2021-10-26 18:41:38
 * @LastEditTime: 2021-10-26 18:56:58
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

bool ishui(char *s){
    int i = 0;
    while (s[i]!='\0'){//获取s长度
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        //cout << s[i-1]<<'\t'<< s[j]<<'\n';
        if (s[i-1]!=s[j])//分别指向头和尾。
        {
            return false;
        }
        i--;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    char s[100];
    gets(s);//获取字符串
    ishui(s) ? cout << "是回文串" : cout << "不是回文串";
    return 0;
}
