/*
 * @Description: 删除字符串中的数字
 * @Author: Leo
 * @Date: 2021-10-24 18:17:54
 * @LastEditTime: 2021-10-24 18:33:33
 */
#include<stdio.h>
#include<algorithm>
using namespace std;

void del_num(char *a){
    int i = 0, j = 0;
    while (a[i]!='\0')
    {
        if (a[i]>='0'&&a[i]<='9')
        {
            i++;
        }
        else{
            a[j++] = a[i++];
        }
    }
    a[j] = '\0';
}

void show_str(char *a){
    int i = 0;
    while (a[i]!='\0')
    {
        printf("%c", a[i]);
        i++;
    }
    printf("\n");
    return;
}

int main(int argc, char const *argv[])
{
    char a[] = {"554353453 world 123aa !!1145145"};
    show_str(a);
    del_num(a);
    show_str(a);
    return 0;
}
