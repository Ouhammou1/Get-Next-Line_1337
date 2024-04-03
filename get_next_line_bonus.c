/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:44:48 by bouhammo          #+#    #+#             */
/*   Updated: 2024/03/28 17:51:24 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_return_line(char *ptr)
{
	int		i;
	char	*str;

	if (ptr[0] == '\0')
		return (NULL);
	i = 0;
	while (ptr[i] != '\0' && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\n')
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (ptr[++i] != '\0' && ptr[i] != '\n')
		str[i] = ptr[i];
	if (ptr[i] == '\n')
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read_string(int fd, char *string)
{
	ssize_t	nbr;
	char	*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	nbr = 1;
	while (!ft_strchar(string, '\n') && nbr > 0)
	{
		nbr = read(fd, buff, BUFFER_SIZE);
		if (nbr == -1)
		{
			free(buff);
			buff = NULL;
			return (NULL);
		}
		buff[nbr] = '\0';
		string = ft_strjoin(string, buff);
	}
	free(buff);
	buff = NULL;
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*string[OPEN_MAX];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1)
	{
		if (fd >= 0 && fd <= OPEN_MAX)
		{
			free(string[fd]);
			string[fd] = NULL;
		}
		return (NULL);
	}
	string[fd] = ft_read_string(fd, string[fd]);
	if (string[fd] == NULL)
	{
		return (NULL);
	}
	line = ft_return_line(string[fd]);
	string[fd] = ft_last_line(string[fd]);
	return (line);
}
