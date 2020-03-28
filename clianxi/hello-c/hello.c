#include<stdio.h>
int main(void)
{
    //输入一行字符，分别统计出其中英文字母、空格、数字和其他字符的个数。
    char ch;
    char eng[]=" ";
    int char_num=0,kongge_num=0,int_num=0,other_num=0;

    while((ch=getchar())!='\n')//回车键结束输入，并且回车符不计入
    {
        if(ch>='a'&&ch<='z'||ch<='z'&&ch>='a')
        {
            kongge_num=1;
        }
        if(ch==' '&&kongge_num == 1)
        {
            kongge_num=0;
        }
        else
        {
            eng[other_num]=ch;
            other_num++;
        }
        //if(ch==' ')
        //{
        //    kongge_num=1;
        //}
    }
    for(int_num=0;int_num<other_num;int_num++)
    {
        printf("%c",eng[int_num]);
    }
        printf("\n");
        printf("%d\n",other_num);
   // printf("字母= %d,空格= %d,数字= %d,其它= %d\n",char_num,kongge_num,int_num,other_num);
    return 0;
}
