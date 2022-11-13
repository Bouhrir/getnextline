/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:19:28 by obouhrir          #+#    #+#             */
/*   Updated: 2022/11/13 14:22:04 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
size_t	lenth(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_join(char *arc, char *buff);
char	*get_befor(char *arc);
char	*get_after(char *arc);

#endif