/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:16:39 by bouhammo          #+#    #+#             */
/*   Updated: 2024/02/27 19:53:27 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3

# endif

char	*get_next_line(int fd);
char	*get_next(int fd, char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get(char *str);
char	*next(char *str);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, char c);

#endif
