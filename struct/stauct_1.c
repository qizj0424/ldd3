
/**********************************************************************************************************************************

1.由下面程序可以看出以下 3 种形式是等价的：
	结构体变量.成员名。
	(*指针变量).成员名。
	指针变量->成员名。

要注意的是，只有“指针变量名”后面才能加“->”，千万不要在成员名如 birthday 后面加“->”


其中第 3 种方式很重要，通常都是使用这种方式，另外两种方式用得不多。链表用的也都是第 3 种方式。

**********************************************************************************************************************************/

#include <stdio.h>
#include <string.h>

struct AGE
{
    int year;
    int month;
    int day;
};

struct STUDENT
{
    char name[20];        //姓名
    int num;              //学号
    struct AGE birthday;  //生日
    float score;          //分数
};

int main(void)
{
    struct STUDENT student1;        /*用struct STUDENT结构体类型定义结构体变量student1*/
    struct STUDENT *p = NULL;       /*定义一个指向struct STUDENT结构体类型的指针变量p*/
    
    p = &student1;                  /*p指向结构体变量student1的首地址, 即第一个成员的地址*/

//第一种
    strcpy((*p).name, "小明");      //(*p).name等价于student1.name
    (*p).birthday.year = 1989;
    (*p).birthday.month = 3;
    (*p).birthday.day = 29;
    (*p).num = 1207041;
    (*p).score = 100;
    printf("name : %s\n", (*p).name);  //(*p).name不能写成p
    printf("birthday : %d-%d-%d\n", (*p).birthday.year, (*p).birthday.month, (*p).birthday.day);
    printf("num : %d\n", (*p).num);
    printf("score : %.1f\n", (*p).score);
    printf("\n\n");    

//第二种
    strcpy(student1.name, "小明");      
    student1.birthday.year = 1989;
    student1.birthday.month = 3;
    student1.birthday.day = 29;
    student1.num = 1207041;
    student1.score = 100;
    printf("name : %s\n", student1.name); 
    printf("birthday : %d-%d-%d\n", student1.birthday.year, student1.birthday.month, student1.birthday.day);
    printf("num : %d\n", student1.num);
    printf("score : %.1f\n", student1.score);
    printf("\n\n");    

//第三种
    strcpy(p->name, "小明");      
    p->birthday.year = 1989;
    p->birthday.month = 3;
    p->birthday.day = 29;
    p->num = 1207041;
    p->score = 100;
    printf("name : %s\n", p->name);  
    printf("birthday : %d-%d-%d\n", p->birthday.year, p->birthday.month, p->birthday.day);
    printf("num : %d\n", p->num);
    printf("score : %.1f\n", p->score);

    
    
    return 0;
}










