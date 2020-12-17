#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <stdio.h> 


typedef struct	fd_list_0
{
	struct fd_list_0		*next;
	int						fd;
	char					*reminder;
}				fd_list;

size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			get_next_line(int fd, char **line);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *s);
char		*ft_substr(char *s, unsigned int start, size_t len);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strchr(char *s, int c);

#endif 
