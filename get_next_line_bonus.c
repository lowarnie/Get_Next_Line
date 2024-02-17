/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowarnie <lowarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:19:44 by lowarnie          #+#    #+#             */
/*   Updated: 2024/02/17 15:30:07 by lowarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_extract_clear(char **stash)
{
	char	*res;
	char	*temp_stash;
	int		i;

	i = 0;
	temp_stash = *stash;
	if (!*stash)
		return (NULL);
	while (temp_stash[i] != '\n' && temp_stash[i] != '\0')
		i++;
	if (temp_stash[i] == '\n')
		i++;
	res = ft_strndup_gnl(temp_stash, i);
	*stash = ft_strndup_gnl((temp_stash + i), (ft_strlen_gnl(temp_stash + i)));
	free(temp_stash);
	return (res);
}

char	*ft_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*str;
	int			ncl;

	ncl = 1;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
		return (ft_free(&stash[fd]));
	if (ft_strchr_gnl(stash[fd], '\n'))
		return (ft_extract_clear(&stash[fd]));
	str = malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (ncl > 0 && !ft_strchr_gnl(stash[fd], '\n'))
	{
		ncl = read(fd, str, BUFFER_SIZE);
		str[ncl] = '\0';
		stash[fd] = ft_strjoin_gnl(stash[fd], str);
	}
	ft_free(&str);
	return (ft_extract_clear(&stash[fd]));
}
/* 
int	main(void)
{
	char	*content;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	while (1)
	{
		content = get_next_line(fd);
		if (!content)
			break ;
		printf("%s", content);
		free(content);
	}
	if (content)
		free(content);
	close(fd);
	return (0);
}
 */