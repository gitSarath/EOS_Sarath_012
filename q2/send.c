#include<stdio.h>
#include<stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>  
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#define buff 128
unsigned char *data_s[buff]={"hello"};
int main()
{
    int fd;
    fd = shm_open("/newfile", O_CREAT | O_RDWR , S_IRUSR | S_IWUSR);
    if(fd == -1)
    {
        perror("ERROR:\n");
        exit(EXIT_FAILURE);
    }
    ftruncate(fd,sizeof(char));

    data_s[buff]=(char *)mmap(NULL,sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED ,fd ,0);
    *data_s[buff]= 0;
    while(1)
    {
        for(int i=0;i<buff;i++)
        {
            *data_s[i]++;
    //    printf("sending data is:%c\n",(*data_s[buff]));
        }
        printf("sending data is:%c",(*data_s[buff]));
        sleep(1);
    }
    return 0;
}