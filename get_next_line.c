/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadrider <hadrider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:55:11 by hadrider          #+#    #+#             */
/*   Updated: 2025/12/22 12:13:00 by hadrider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_save(int fd, char *text)
{
	char	*buf;
	int		bytes;

	if (!text)
	{
		text = malloc(1);
		if (!text)
			return (NULL);
		text[0] = '\0';
	}
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(text), NULL);
	bytes = 0;
	while (!ft_strchr(text, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes == -1)
			return (free(buf), free(text), NULL);
		buf[bytes] = '\0';
		text = ft_strjoin(text, buf);
	}
	return (free(buf), text);
}

static char	*extract_line(char *text)
{
	int		i;
	char	*line;

	if (!text || !text[0])
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*clean_save(char *text)
{
	int		i;
	int		j;
	char	*new_text;

	i = 0;
	j = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
		return (free(text), NULL);
	new_text = malloc(ft_strlen(text) - i);
	if (!new_text)
		return (free(text), NULL);
	i++;
	while (text[i])
		new_text[j++] = text[i++];
	new_text[j] = '\0';
	free(text);
	return (new_text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE <= 2147483647)
		return (free(text), text = NULL, NULL);
	text = read_and_save(fd, text);
	if (!text)
		return (NULL);
	line = extract_line(text);
	if (line == NULL)
		return (free(text), text = NULL, NULL);
	text = clean_save(text);
	return (line);
}
