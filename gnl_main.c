#include "get_next_line.h"

int main(void)//int argc, char *argv[])
{
/*
	char str1[] = "hello world";
	char str2[] = " oh hi mark";
	char *str3;

	str3 = NULL;
	printf("%s\n", ft_strjoin(str1, str2));
	printf("%s\n", ft_strjoin("", str2));
	printf("%s\n", ft_strjoin(str3, str2));
*/

	char *line;
	int fd;
	int fd2;
	int fd3;

	fd = open("texts2/text.txt", O_RDONLY);
	fd2 = open("texts2/text2.txt", O_RDONLY);
	fd3 = open("texts2/text3.txt", O_RDONLY);
	

	get_next_line(fd, &line);
	printf("%s\n\n", line);
	free(line);
	
	get_next_line(fd, &line);
	printf("%s\n\n", line);
	free(line);

	get_next_line(fd2, &line);
	printf("%s\n\n", line);
	free(line);
	
	get_next_line(fd, &line);
	printf("%s\n\n", line);
	free(line);

	get_next_line(fd2, &line);
	printf("%s\n\n", line);
	free(line);

	get_next_line(fd3, &line);
	printf("%s\n\n", line);
	free(line);
/*
	int i;
	
	i = 1;
	while (argc > 1)
	{
//	line = (char *)malloc(sizeof(char));
		fd = open(argv[i], O_RDONLY);
		while((get_next_line(fd, &line)))
		{
			printf("%s\n\n", line);
			free(line);
		}	

		get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
		argc--;
		i++;
	}
*/
	return (1);
}
