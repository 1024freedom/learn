src=$(wildcard *.c)#匹配当前目录所有.c文件赋值给src
target=$(patsubst %.c,%.o,$(src))#没有依赖，只是单纯的名字

ALL:$(target)

%.o:%.c
	gcc -c $< -o $@
clean:
	-rm -rf $(target)
.PHONY:clean ALL