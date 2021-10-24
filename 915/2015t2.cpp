/*
 * @Description: 统计字符串字符个数
 * @Author: Leo
 * @Date: 2021-10-23 21:08:53
 * @LastEditTime: 2021-10-24 18:16:57
 */
#include<stdio.h>

void tongjizifu(char s[]){
    int i = 0;
    int si = 0, zm = 0, other = 0;
    while (s[i]!='\0')
    {
        if (s[i]>='0'&&s[i]<='9')
            si++;
        if ((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z'))
            zm++;
        else
            other++;
        i++;
    }
    printf("数字：%d\n字母：%d\n其他：%d\n", si, zm, other);
}

int main(int argc, char const *argv[])
{
    char s[] = {"iiii8888hhhh6666::::[[[[]]]]qqqq"};
    tongjizifu(s);
    return 0;
}
