/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:11:16 by sranaivo          #+#    #+#             */
/*   Updated: 2024/03/26 15:12:13 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_full_line(const char *line)
{
	char	*f_line;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	f_line = ft_substr(line, 0, (i + 1));
	return (f_line);
}

char	*get_static_line(const char *line)
{
	char	*static_line;
	int		i;
	int		len;

	if (!line)
		return (NULL);
	i = 0;
	len = (int)ft_strlen(line);
	while (line[i])
		if (line[i++] == '\n')
			break ;
	static_line = ft_substr(line, (i), len);
	return (static_line);
}

int	check_line(const char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n' || line[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*static_line = NULL;
	char		*line;
	char		*temp;
	char		*buf;
	int			r;

	if (fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!check_line(static_line))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == 0)
			break ;
		buf[r] = '\0';
		if (!static_line)
			static_line = ft_strjoin("", buf);
		else
			static_line = ft_strjoin(static_line, buf);
	}
	free(buf);
	temp = get_static_line(static_line);
	line = get_full_line(static_line);
	free(static_line);
	static_line = ft_strjoin("", temp);
	return (line);
}

/*int	main(void)
{
	int	fd;

	fd = open("file", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}*/
