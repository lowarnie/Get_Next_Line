/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowarnie <lowarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:21:10 by lowarnie          #+#    #+#             */
/*   Updated: 2024/02/17 14:23:11 by lowarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_extract_clear(char **stash);
char	*ft_free(char **str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strndup_gnl(char *s1, int l);

int		ft_strchr_gnl(char *s, int c);
int		ft_strlen_gnl(char *str);

#endif