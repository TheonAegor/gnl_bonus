#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <stdio.h> 

void create_pointer(char **line)
{
	char *p;
	
	printf("address of line before malloc:%p\n", *line);
	*line = malloc(sizeof(char));
	printf("address of line after malloc:%p\n", *line);
	p = malloc(sizeof(char));
	printf("address of p in func:%p\n", p);
	if (!*line)
		printf("*line doesn't");
	
}

int main(void)
{
	char *buf;
	
	buf = malloc(sizeof(char) * 10);
	printf("%ld\n", read(0, buf, 10));	
	printf("%s\n", buf);	
	
/*
	char *p;
	char *p2;
	char *line;
	int i;
	char b[] = "hello world again privet ";

	i = 0;
//	p = malloc(sizeof(char) * 10);
//	free(p);
//	p = malloc(sizeof(char));
//	p2 = malloc(sizeof(char));
	printf("address of line in main:%p\n", line);//откуда адрес если ничего не замолочено??
	create_pointer(&line);
	printf("address of p:%p\n", p);
	printf("address of p2:%p\n", p2);
*/
/*
	while(i < ft_strlen(b))
	{
		*p++ = b[i];
		i++;
	}
	printf("%d\n", i);
	p = p - i;
	while(*p)
	{
		printf("%c", *p);
		p++;
	}
	printf("%d\n", ft_strlen(p));
*/
	return (0);
}
