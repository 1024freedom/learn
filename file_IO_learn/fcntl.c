#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
    char buf[1024];
    int flags,n;
    //获取标准输入的文件状态标志
    flags=fcntl(STDIN_FILENO,F_GETFL);
    if(flags==-1){
        perror("fcntl F_GETFL error");
        exit(1);
    }
    //将O_NONBLOCK标志添加到文件状态标志中，实现非阻塞读取
    flags|=O_NONBLOCK;
    //设置标准输入的文件状态标志
    int ret=fcntl(STDIN_FILENO,F_SETFL,flags);
    if(ret==-1){
        perror("fcntl F_SETFL error");
        exit(1);
    }
}