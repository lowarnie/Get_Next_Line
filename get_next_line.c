/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowarnie <lowarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:07:28 by lowarnie          #+#    #+#             */
/*   Updated: 2024/02/17 15:30:30 by lowarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*stash;
	char		*str;
	int			ncl;

	ncl = 1;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
		return (ft_free(&stash));
	if (ft_strchr_gnl(stash, '\n'))
		return (ft_extract_clear(&stash));
	str = malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (ncl > 0 && !ft_strchr_gnl(stash, '\n'))
	{
		ncl = read(fd, str, BUFFER_SIZE);
		str[ncl] = '\0';
		stash = ft_strjoin_gnl(stash, str);
	}
	ft_free(&str);
	return (ft_extract_clear(&stash));
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