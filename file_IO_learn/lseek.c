#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
    int fd,n;
    char msg[]="It is a test message.\n";
    char ch;
    fd=open("lseek.txt",O_RDWR|O_CREAT,0644);
    if(fd<0){
        perror("open lseek test error");
        exit(1);
    }
    //lseek返回从文件开头计算的偏移量
    write(fd,msg,strlen(msg));
    lseek(fd,0,SEEK_SET);
    int length=lseek(fd,0,SEEK_END);
    printf("length of file is %d\n",length);
    //写一个空字符到文件末尾，将文件长度扩展为length+1
    write(fd,"\0",1);
    //truncate同样实现扩展文件长度
    //int ret=truncate("lseek.txt",length+1);
    // if(ret<0){
    //     perror("truncate error");
    //     exit(1);
    // }
    // printf("ret=%d\n",ret);
}