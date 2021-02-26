#include<stdio.h>

int  main(void)
{

   long unsigned int *p = NULL;

   printf("%d\n",sizeof(*p));

}




//(typedef int *ptr;  ptr p =NULL;)
//（sizeof(all type *)=4, 
