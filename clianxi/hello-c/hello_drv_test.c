//
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <unistd.h>
//#include <stdio.h>
//#include <string.h>
//
///*
// * ./hello_drv_test -w abc
// * ./hello_drv_test -r
// */
//int main(int argc, char **argv)
//{
//	int fd;
//	int len;
//	
//    printf("_________%d_________\n",argc);
//	/* 1. 判断参数 */
//
//	/* 2. 打开文件 */
//	fd = open("/dev/hello", O_RDWR);
//	if (fd == -1)
//	{
//		printf("_______%d___________\n",__LINE__);
//		printf("can not open file /dev/hello\n");
//		return -1;
//	}
//
//}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
        int len;
        char buf[1024];

        int fd = open("/home/book/a.txt", O_RDWR);
        printf("______%d_______\n",fd);
        
        len = strlen(argv[1]) + 1;
        write(fd, argv[1], len);
        //printf("______%d_______\n",size);
        
        len = read(fd, buf, 1024);
        //buf[1023] = '\0';
        printf("______%d_______\n",len);
        printf("APP read : %s\n", buf);

        if (fd >= 0) close(fd);
        return 0;
}

