#include "get_next_line.h"

int			ft_strlen(char *s)
{
	int		len;

	len = 0;
	while(*s)
	{
		len++;
		s++;
	}
	return (len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	len;
	
	len = nmemb;
	if(!(p = malloc(nmemb * size)))
		return (NULL);
	while(nmemb)
	{
		*p = '\0';
		nmemb--;
		p++;
	}
	return (p - len);
}

size_t		ft_strlcpy(char *dst, const char *src,
		size_t size)
{
	int			result_len;
	size_t		i;

	if (!dst || !src)
		return (0);
	i = 0;
	while(src[i])
		i++;
	result_len = i;
	if (size == 0)
		return (result_len);
	i = 0;
	while (size - 1 > i && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (result_len);
}
static char	*ft_copy(char *dst, const char *src)
{
	int		i;

	if (src[0] == '\0')
	{
		dst[0] = '\0';
		return (dst);
	}
	i = -1;
	while (src[++i] != '\0')
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strdup(const char *s)
{
	char	*p;
	int		len;

	len = ft_strlen((char *)s);
	if (!s)
		return (NULL);
	if (*s == '\0')
		len = 1;
	if (!(p = malloc(sizeof(char) * len + 1)))
		return (NULL);
	return (ft_copy(p, s));
}

char			*ft_strjoin(char  *s1, char  *s2)
{
	char		*p;
	int			len_s1;
	int			len_s2;
	int			i;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(p = ft_calloc((len_s1 + len_s2 + 1), sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < len_s1)
	{
		p[i] = s1[i];
	}
	i = -1;
	while (++i < len_s2)
	{
		p[i + len_s1] = s2[i];
	}
	p[len_s1 + len_s2] = '\0';
	return (p);
}

char * ft_substr(char *s, unsigned int start, size_t len)
{
	char			*p;
	size_t			i;
	size_t			len_s;

	i = 0;
	if (!s)
		return (0);
	len_s = ft_strlen((char *)s);
	if ((unsigned int)len_s - start < len)
		len = len_s - start;
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len && i + start < len_s)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char		*ft_strchr(char *s, int c)
{
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	if (ft_strlen(s) == 0)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}
