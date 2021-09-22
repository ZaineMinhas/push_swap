/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:13:57 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/19 16:27:20 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_check_error(int fd, char **line)
{
	char	*buff;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1 || !line)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	return (buff);
}

int	ft_backslash_checker(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*ft_get_line(char *str)
{
	char	*dest;
	size_t	size;
	size_t	i;

	if (!str)
		return (NULL);
	size = 0;
	i = -1;
	while (str[size] && str[size] != '\n')
		size++;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	while (++i < size + 1)
		dest[i] = 0;
	if (!dest)
		return (NULL);
	size = 0;
	while (str[size] && str[size] != '\n')
	{
		dest[size] = str[size];
		size++;
	}
	return (dest);
}

int	ft_return(char **buff, int i, char **line, char **str_save)
{
	free(*buff);
	*line = ft_get_line(*str_save);
	if (!line)
		return (-1);
	*str_save = ft_strchr_dup_remix(*str_save, '\n');
	if (!*str_save && i != 0)
		return (-1);
	if (i)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str_save;
	char		*buff;
	int			i;

	buff = ft_check_error(fd, line);
	if (!buff)
		return (-1);
	i = 1;
	while (!ft_backslash_checker(str_save) && i)
	{
		i = (int)read(fd, buff, BUFFER_SIZE);
		if (i < 0)
		{
			free(buff);
			return (-1);
		}
		buff[i] = 0;
		str_save = ft_gnljoin(str_save, buff);
		if (!str_save)
			return (-1);
	}
	return (ft_return(&buff, i, line, &str_save));
}
