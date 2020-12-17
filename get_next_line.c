# include "get_next_line.h"


void ft_bzero(char *s)
{
	while(*s)
	{
		*s++ = '\0';
	}
}
/*
void	ft_lstclear(fd_list **current)
{

	if (*current)
	{
		free(current->reminder);
		free(current);
	}
}
*/
fd_list	*ft_lstnew(int fd)
{
	fd_list *new;	
	
	new = malloc(sizeof(fd_list));
	new->reminder = NULL;	
	new->fd = fd;
	new->next = NULL;
//	printf("fd = %d, rem = %s\n", new->fd, new->reminder);
	return(new);
}

fd_list *ft_lstadd_front(fd_list *last, int fd)
{
	fd_list *tmp;
	fd_list *new;

	new = ft_lstnew(fd);	
	if (new)	
	{
		tmp = last;
		while(tmp->next)
		{
//			printf("fd = %d, rem = %s\n", tmp->fd, tmp->reminder);
			tmp = tmp->next;
		}
		tmp->next = new;
	}
	return(last);
	
}

fd_list *ft_find_fd(fd_list *new, int fd)
{
	fd_list		*tmp;

	if (!(fd))
		return (NULL);	
	tmp = new;
//	printf("tmp->fd = %d, fd = %d\n", tmp->fd, fd);
	while (tmp->next)
	{
		if (tmp->fd == fd)
		{
//			printf("fd is found, tmp->fd = %d, fd = %d", tmp->fd, fd); 
			return(tmp);
		}
		tmp = tmp->next;
	}
	return(ft_find_fd(ft_lstadd_front(new, fd), fd));
}

void ft_print_all(fd_list *last)
{
	fd_list *tmp;

	tmp = last;
	while(tmp->next)
	{
		printf("fd = %d, reminder = %s\n", tmp->fd, tmp->reminder);
		tmp = tmp->next;
	}
}

char	*ft_strnew(size_t size)
{
	return((char *)malloc(sizeof(char)  * (size + 1)));
}

void ft_change_rem(fd_list **last, char *p_n)
{
	(*last)->reminder = ft_strdup(p_n);
}

int			get_next_line(int fd, char **line)
{
	char *buf;
	char *p_n;
	char *tmp;
	int flag;
	static fd_list *new;
	int bytes_was_read;
	static int i;
	static int n;
//	char *str;
	
	if (fd == -1)
		return (0);
	if (!(new)) //если нью не существует - создай первый лист
	{
//		printf("create new list in %d time\n", i);
		new = ft_lstnew(fd);
		i++;
	}
	else  // если существует ищи в списке такой фд
	{
//		printf("go to findl_fd in %d time\n", n);
		new = ft_find_fd(new, fd);
		n++;
	}
	ft_print_all(new);
	if (new->reminder)
	{
		if ((p_n = ft_strchr(new->reminder, '\n')))
			p_n[0] = '\0';
//		printf("%s\n+++++++++++++++++++++\n", reminder); //it works
		*line = ft_strdup(new->reminder);
//		printf("line = reminder: %s\n", *line);
		if (p_n)
		{
//			tmp = new->reminder;
//			ft_change_rem(&new, ++p_n);
			new->reminder = ft_strdup(++p_n);
//			printf("%s\n---------------\n", reminder); //it works
//			free(tmp);
//			printf("%s\n---------------\n", reminder); //it works
//			printf("fd = %d, reminder = %s\n", new->fd, new->reminder);
			return (1);
		}
	}
	else
		*line = ft_strnew(1);
//	printf("fd = %d, reminder = %s\n", new->fd, new->reminder);
	flag = 1;
	p_n = NULL;
	if (!(buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1)))
		return (-1);
	while(!(p_n) && (bytes_was_read = read(fd, buf, BUFFER_SIZE)) && flag)
	{
		buf[bytes_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			flag = 0;	
			*p_n = '\0';
			p_n++;
			new->reminder = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
//		printf("buf = %s; line =%s\n", buf, *line);
		free(tmp);
	}
	if (bytes_was_read <= 0)
		return (0);
	return (1);
}
