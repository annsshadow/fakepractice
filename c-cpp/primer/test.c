#include <stdio.h>

/*
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <sys/mman.h>
#include <time.h>
*/

int main()
{
    /*
    char *a="abcd";
    printf("string_strlen:%d\n",strlen(a));
    printf("string_sizeof:%d\n",sizeof(a));

    long long int b;
    printf("long long long int:%d\n",strlen(b));
    printf("long long long int:%d\n",sizeof(b));
    */

    /*
    int fd=0;
    if((fd = open("/usr/local/nginx/html/file.txt", O_RDWR)) == -1 )
    {
    	printf("open erro £¡\n");
    	exit(-1);
    }
    */

    /*
    struct stat filestat;
    //fstat(fd ,&filestat);
    stat("/usr/local/nginx/html/file.txt",filestat)
    printf("file.txt size:%d\n",filestat.st_size);
    */


    int transfer_sum = 0;
    int file_length = 100;
    int sub = 0;
    int percent = 0.0;
    for(; transfer_sum < file_length; sub += 2)
    {
        percent = (transfer_sum & 0xff00000000000000) ? transfer_sum / (file_length / 100) : transfer_sum * 100 / file_length;
        printf("Download finished--1->%d%%\n", percent);
        percent = transfer_sum / file_length / 100;
        printf("Download finished--2->%d%%\n", percent);
        percent = (transfer_sum > 0) ? transfer_sum / (file_length / 100) : transfer_sum * 100 / file_length;
        printf("Download finished--3->%d%%\n", percent);
        transfer_sum += sub;
    }

    /*
    printf("%d\n",0xff00000000000000);
    printf("%ld\n",0xff00000000000000);
    printf("%u\n",0xff00000000000000);
    printf("%f\n",0xff00000000000000);
    printf("%o\n",0xff00000000000000);
    printf("%x\n",0xff00000000000000);
    printf("%c\n",0xff00000000000000);
    printf("%s\n",0xff00000000000000);
    */
    return 0;
}
