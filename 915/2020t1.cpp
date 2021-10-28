/*
 * @Description: 输出abcd使得，abcd+cabd=9102
 * @Author: Leo
 * @Date: 2021-10-28 18:59:00
 * @LastEditTime: 2021-10-28 19:12:35
 */
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // for (int a = 0; a < 10; a++)
    // {
    //     for (int b = 0; b < 10; b++)
    //     {
    //         for (int c = 0; c < 10; c++)
    //         {
    //             for (int d = 0; d < 10; d++)
    //             {
    //                 int m, n;
    //                 m = a * 1000 + b * 100 + c * 10 + d;
    //                 n = c * 1000 + a * 100 + b * 10 + d;
    //                 if (m+n==9102)
    //                     printf("a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);
    //             }
    //         }
    //     }
    // }
    
    int a, b, c, d;
    for (int i = 0; i < 10000; i++)
    {
        a = i / 1000;
        b = i / 100 % 10;
        c = i / 10 % 10;
        d = i % 10;
        if ( c * 1000 + a * 100 + b * 10 + d+i==9102)
        {
            printf("a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);
        }
    }
    return 0;
}
