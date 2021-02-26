#include<stdio.h>
struct dangdang
{
    char email[30];
    char name[30];
    char addr[100];
    int num;
    int bugnum;
    char tel[20];
    char phone[20];
    double RMB;

}dbdd[2]={{"1171546435@qq.com","lj","重庆市",34,77,"18778654634","4334564",1000},
{"453454534@qq.com","fd","贵阳",43,65,"543475634","45345",54444}
};//初始化
void main()
{
    char str[50];
    int i;
    int num = sizeof(dbdd)/sizeof(struct dangdang);
    scanf("%s",str);
    printf("你要查找的是%s",str);

    for(i=0;i<num;i++)
    {
        if(strcmp(str,dbdd[i].phone)==0)
        {
            printf("找到,邮件为%s,姓名为%s，地址为%s",dbdd[i].email,dbdd[i].name,dbdd[i].addr);
        }
    }
    system("pause");
}
