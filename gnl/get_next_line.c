/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:30:53 by jacopo            #+#    #+#             */
/*   Updated: 2023/03/10 11:16:53 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_info(int fd, char *raw, char *buf)
{
	ssize_t		byte;
	char		*char_tmp;

	byte = 1;
	while (byte != '\0')
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
			return (NULL);
		else if (byte == 0)
			break ;
		buf[byte] = '\0';
		if (!raw)
			raw = ft_strdup("");
		char_tmp = raw;
		raw = ft_strjoin(char_tmp, buf);
		free(char_tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (raw);
}

static char	*ft_clean(const char *raw, size_t *i)
{
	size_t	j;
	size_t	pos;
	char	*str;

	pos = *i;
	j = 0;
	if (!raw[pos])
		return (NULL);
	while (raw[pos] && raw[pos] != '\n')
		pos++;
	str = ft_substr(raw, j, (++pos));
	*i = pos;
	if (!ft_strchr(raw, '\n'))
		return (str);
	str[pos] = '\0';
	return (str);
}

static char	*ft_memory(char *raw, size_t *i)
{
	char	*tmp;
	size_t	j;

	j = *i;
	tmp = ft_substr(raw, j, (ft_strlen(raw) - j));
	if (*tmp == '\0')
	{
		free (tmp);
		tmp = NULL;
	}
	free(raw);
	raw = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*raw;
	char		*str_to_return;
	size_t		i;
	char		*buf;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	raw = ft_get_info(fd, raw, buf);
	free(buf);
	buf = NULL;
	if (!raw)
		return (NULL);
	i = 0;
	str_to_return = ft_clean(raw, &i);
	raw = ft_memory(raw, &i);
	return (str_to_return);
}
