/*
 * @Description: 字符串0~9各有几个
 * @Author: Leo
 * @Date: 2021-11-02 18:48:34
 * @LastEditTime: 2021-11-02 19:25:51
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

// int cntnum(string s){
//     int i = 0, count = 0;
    // while (s[i]!='\0')
    // {
    //     if (s[i]>='0'&&s[i]<='9')
    //         count++;
    //     i++;
    // }
//     return count;
// }
int main(int argc, char const *argv[])
{
    string str;
    int a[10]={0},i=0;
    while (1)
    {
        cin >> str;
        if (str=="*#*")
            break;
        i = 0;
        while (str[i]!='\0')
        {
            if (str[i]>='0'&&str[i]<='9'){
                a[str[i] - '0']++;
                //cout << str[i] - '0' << ' ';
            }
            //cout << '\n';
            i++;
        }
    }
    for (int j = 0; j < 10; j++)
    {
        printf("%d有%d个\n", j, a[j]);
    }
    
    
    return 0;
}
