/*
 * @Description: 公司发礼品
 * @Author: Leo
 * @Date: 2021-10-29 19:13:25
 * @LastEditTime: 2021-10-30 19:15:45
 * 难点在于：
 * 1.题目没读懂（主要难点）
 * 2.回溯条件
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

vector<int> temp;

int add(vector<int> a){//向量元素求和
    int res = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        res += a[i];
    }
    return res;
}
/*这里也可以用numeric中的accumulate函数进行求和具体用法为
*accumulate(a.begin(),a.end(),0)
*/


void dfs(vector<int> val,int cur,int &count){
    if (add(temp)==200)//输出满足的组合
    {
        count++;
        for (size_t i = 0; i < temp.size(); i++)
            cout << temp[i] << ' ';
        cout << '\n';
    }
    else if(add(temp)>200){//递归return条件
        return;
    }
    for (size_t i = cur; i < val.size(); i++)//主代码：回溯部分
    {
        temp.push_back(val[i]);
        dfs(val, i, count);
        temp.pop_back();//回溯
    }
    
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> val(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int count = 0;
    cout << "可能的方案"<<'\n';
    dfs(val, 0, count);
    cout << "总的方案数" << count << '\n';
    return 0;
}
