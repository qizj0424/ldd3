
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
                                                                                
int main(int argc, char* argv[])
{
        int fd;
        fd = open("/home/gaobsh/a.txt", O_RDONLY);
        //if (fd >= 0) close(fd);
        return 0;
}

