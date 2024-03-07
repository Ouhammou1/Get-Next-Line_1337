/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:18:02 by bouhammo          #+#    #+#             */
/*   Updated: 2024/02/27 19:52:09 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*get(char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[i--] = '\0';
	while (i >= 0)
	{
		ptr[i] = str[i];
		i--;
	}
	return (ptr);
}

char	*next(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	ptr = ft_strdup(str + i);
	free(str);
	return (ptr);
}

char	*get_next(int fd, char *str)
{
	int		a;
	char	*buffer;

	a = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	while (a > 0)
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[a] = 0;
		str = ft_strjoin(str, buffer);
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		if (fd > 0 && fd < 256)
		{
			free(str[fd]);
			str[fd] = NULL;
		}
		return (NULL);
	}
	str[fd] = get_next(fd, str[fd]);
	if (str[fd] == NULL)
	{
		return (NULL);
	}
	line = get(str[fd]);
	str[fd] = next(str[fd]);
	return (line);
}
