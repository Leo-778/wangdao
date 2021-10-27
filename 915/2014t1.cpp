/*
 * @Description: 10进制转2进制、8进制、16进制
 * @Author: Leo
 * @Date: 2021-10-25 18:16:26
 * @LastEditTime: 2021-10-26 18:41:03
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

void BinTo(int x,int n){//10进制转2进制、8进制
    if(n==2||n==8){
        if (x==0)
        {
            return;
        }
        else{
            BinTo(x / n, n);
            cout << x%n;
        }
    }
    if(n==16){
        if (x==0)
        {
            return;
        }
        else{
            BinTo(x / n, n);
            if (x%n>9)
            {
                switch (x%16)
                {
                case 10:
                    cout << 'A';
                    break;
                case 11:
                    cout << 'B';
                    break;
                case 12:
                    cout << 'C';
                    break;
                case 13:
                    cout << 'D';
                    break;
                case 14:
                    cout << 'E';
                    break;
                case 15:
                    cout << 'F';
                    break;
                case 16:
                    cout << 'D';
                    break;      
                }
            }
            else
                cout << x % n;
        }
    }
}


int main(int argc, char const *argv[])
{
    int x ;
    cout << "输入十进制数字：";
    cin >> x;
    cout << "二进制：";
    BinTo(x, 2);
    cout << '\n'<<"八进制：";
    BinTo(x, 8);
    cout << '\n'<<"十六进制:";
    BinTo(x, 16);
    return 0;
}
