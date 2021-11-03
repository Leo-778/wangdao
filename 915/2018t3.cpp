/*
 * @Description: 判断日期是这年第几天
 * @Author: Leo
 * @Date: 2021-11-03 20:07:48
 * @LastEditTime: 2021-11-03 20:33:05
 */
#include<stdio.h>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int date,sum=0,leap=0;
    cin >> date;
    int day = date % 100;
    int month = (date / 100) % 100;
    int year = date / 10000;
    //cout << year<<' '<< month<<' '<<day<<' ';
    switch (month)
    {
    case 1:
        sum = 0;
        break;
    case 2:
        sum = 31;
        break;
    case 3:
        sum = 31+28;
        break;
    case 4:
        sum = 31+28+31;
        break;
    case 5:
        sum = 31+28+31+30;
        break;
    case 6:
        sum = 31+28+31+30+31;
        break;
    case 7:
        sum = 31+28+31+30+31+30;
        break;
    case 8:
        sum = 31+28+31+30+31+30+31;
        break;
    case 9:
        sum = 31+28+31+30+31+30+31+31;
        break;
    case 10:
        sum = 31+28+31+30+31+30+31+31+30;
        break;
    case 11:
        sum = 31+28+31+30+31+30+31+31+30+31;
        break;
    case 12:
        sum = 31+28+31+30+31+30+31+31+30+31+30;
        break;
    default:
        break;
    }
    sum = sum + day;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        leap = 1;
    if (leap==1&&month>2)
    {
        sum++;
    }
    cout << sum<<'\n';
    
    return 0;
}
