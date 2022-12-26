#include<stdio.h>
#include<stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>  
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#define buff 128
char *data_r[buff];
int main()
{
    int fd;
    fd = shm_open("/newfile", O_CREAT | O_RDWR , S_IRUSR | S_IWUSR);
    if(fd==-1)
    {
        perror("ERROR:\n");
        exit(EXIT_FAILURE);
    }
    ftruncate(fd,sizeof(char));

    data_r[]=(char *)mmap(NULL,sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED ,fd ,0);
    // *data_r[] = 0;
    while(1)
    {
        printf("sending data is:%c\n",(*data_r));
        sleep(1);
    }
    return 0;
}
