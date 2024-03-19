/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:17:37 by bouhammo          #+#    #+#             */
/*   Updated: 2024/03/19 16:51:09 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
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
	ptr[i] = '\0';
	i--;
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
	ptr = ft_strdup(str + i);
	free(str);
	return (ptr);
}

char	*get_next(char *str, int fd)
{
	int		a;
	char	*buffer;

	a = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (a > 0)
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[a] = '\0';
		str = ft_strjoin(str, buffer);
		if (ft_strchar(buffer, '\n') != NULL)
		{
			break ;
		}
	}
	free(buffer);
	buffer = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = get_next(str, fd);
	if (str == NULL)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line = get(str);
	str = next(str);
	return (line);
}
