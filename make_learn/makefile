src=$(wildcard *.c)#匹配当前目录所有.c文件赋值给src
target=$(patsubst %.c,%.o,$(src))#没有依赖，只是单纯的名字

ALL:$(target)

%.o:%.c#不能用src，否则只会匹配第一个
	gcc -c $< -o $@
clean:
	-rm -rf $(target)
.PHONY:clean ALL
#命令行直接输入make即可运行