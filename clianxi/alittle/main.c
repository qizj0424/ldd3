#include <stdio.h>

int main()
{
    int ret,value;
    scanf("%x",&value);
    ret =  (value & 0xff);
    printf("###########%x############\n",ret);
    ret = (((value >> 8) & 0xff));
    printf("###########%x############\n",ret);
    return 0;
}

