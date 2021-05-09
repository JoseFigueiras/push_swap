#include "get_next_line.h"

int		has_nl(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

char	*join_str(char const *str1, char const *str2)
{
	size_t	str1_len;
	size_t	str2_len;
	size_t	tot_len;
	char	*ret;

	if (!str1 && !str2)
		return (0);
	str1_len = ft_len((char *)str1);
	str2_len = ft_len((char *)str2);
	tot_len = str1_len + str2_len;
	ret = malloc(tot_len + 1);
	if (!ret)
		return (0);
	ft_memory(ret, str1, str1_len);
	ft_memory(ret + str1_len, str2, str2_len);
	ret[tot_len] = '\0';
	free((char *)str1);
	return (ret);
}

size_t	ft_len(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memory(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}
