#include "get_next_line.h"

static int	free_and_return_error(char *to_free)
{
	free(to_free);
	return (-1);
}

static char	*get_line(char *str)
{
	int		i;
	char	*ret;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ret = malloc(i + 1);
	if (!ret)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char	*get_save(char *save)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	ret = malloc((ft_len(save) - i) + 1);
	if (!ret)
		return (0);
	i++;
	while (save[i])
		ret[j++] = save[i++];
	ret[j] = '\0';
	free(save);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save;
	int				reader;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (-1);
	reader = 1;
	while (!has_nl(save) && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
			return (free_and_return_error(buff));
		buff[reader] = '\0';
		save = join_str(save, buff);
	}
	free(buff);
	*line = get_line(save);
	save = get_save(save);
	if (reader == 0)
		return (0);
	return (1);
}
