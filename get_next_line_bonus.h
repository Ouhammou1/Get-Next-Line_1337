/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:45:12 by bouhammo          #+#    #+#             */
/*   Updated: 2024/03/28 02:45:14 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_read_string(int fd, char *string);
char	*ft_strchar(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_return_line(char *ptr);
char	*ft_last_line(char *str);
size_t	ft_strlen(char *ptr);
char	*ft_join(char *s, char *s1, char *s2);

#endif