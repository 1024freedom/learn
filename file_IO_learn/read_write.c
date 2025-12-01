#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[]){
    char buf[1024];        // 缓冲区，用于存储每次读取的数据
    int n = 0;             // 实际读取的字节数
    
    // 打开源文件（只读模式）
    int fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1){         // 检查文件打开是否成功
        perror("open argv1 error");  // 输出错误信息
        exit(1);           // 打开失败，退出程序
    }
    
    // 打开目标文件（读写模式，如果不存在则创建，如果文件已存在，将其长度截断为0）
    int fd2 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);//第三个参数为文件权限，0表示八进制
    if(fd2 == -1){         // 检查文件打开是否成功
        perror("open argv2 error");  // 输出错误信息
        exit(1);           // 打开失败，退出程序
    }
    
    // 循环读取源文件内容并写入目标文件
    while((n = read(fd1, buf, sizeof(buf))) != 0){
        if(n < 0){         // 读取错误处理
            perror("read argv1 error");  // 输出读取错误信息
            break;         // 跳出循环
        }
        // 将读取到的数据写入目标文件
        write(fd2, buf, n);
    }
    
    // 关闭文件描述符，释放系统资源
    close(fd1);
    close(fd2);
    
    return 0;  // 程序正常结束
}