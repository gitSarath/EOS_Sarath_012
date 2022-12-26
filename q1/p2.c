#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>
int main()
{
    int count=0;
    int fd;
    char buff[1024];
    fd=open("desdfifo",O_RDONLY);
    read(fd,buff,sizeof(buff));
    for(int i=0;i<1024;i++)
    {
        if(buff[i]=='s')
        count++;
    }
    printf("the no of occurance of character is:%d\n",count);
    return 0;
}