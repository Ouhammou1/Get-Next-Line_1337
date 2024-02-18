/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:17:08 by bouhammo          #+#    #+#             */
/*   Updated: 2024/02/11 15:17:16 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		return (0);
	}
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strdup(char *s)
{
	int		k;
	char	*ptr;
	int		i;

	i = 0;
	if (!s[0])
		return (NULL);
	if (!s)
		return (NULL);
	k = ft_strlen(s);
	ptr = (char *)malloc((k + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < k)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;
	int		s2len;
	int		s1len;

	if (s1 == NULL)
		return (ft_strdup(s2));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (ptr == NULL)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (i < s1len)
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2len)
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}
char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == '\0' && (char)c == '\0')
		return ((char *)(str + i));
	return (0);
}
