#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include<stdlib.h>
int main()
{
    char msg[] = {"welcomes you sarath\n"};
    int fd;
    fd = open("desdfifo",O_WRONLY);
    if(fd = = -1)
    {
        perror("ERROR1\n");
        exit(EXIT_FAILURE);
    }
    write(fd,msg,sizeof(msg));
    close(fd);
    return 0;
}