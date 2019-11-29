#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd,td;
    char val[] = "helloworld";
    fd = open("/home/book/work/clianxi/hello-b/hellodev.c", O_RDWR);
    if(fd < 0){
        printf("can't open!\n");
    }
    td= write(fd, &val, 10);
    printf("%d\n",td);
    return 0;
}
