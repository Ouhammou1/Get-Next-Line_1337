/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:16:39 by bouhammo          #+#    #+#             */
/*   Updated: 2024/02/11 15:16:46 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef NEXT_LINE
# define NEXT_LINE

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
char	*ft_strchr(char *str, int c);

#endif
