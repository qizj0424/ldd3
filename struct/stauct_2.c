# include <stdio.h>

struct STU
{
    char name[20];
    int age;
    char sex;
    char num[20];
};

int main(void)
{
    int i = 0;
    struct STU stu[3] = {{"小红", 22, 'F', "Z1207031"}, {"小明", 21, 'M', "Z1207035"}, {"小七", 23, 'F', "Z1207022"}};
    struct STU *p = stu;
    for (; p<stu+3; ++p)
    {
        printf("name:%s; age:%d; sex:%c; num:%s\n", p->name, p->age, p->sex, p->num);
    }
    printf("\n\n");    
 
    p = stu; 
    for (; i<3; ++i)
    {
        printf("name:%s; age:%d; sex:%c; num:%s\n", p[i].name, p[i].age, p[i].sex, p[i].num);
    }
    return 0;
}
