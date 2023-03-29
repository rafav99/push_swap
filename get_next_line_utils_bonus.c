/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaldes- <rvaldes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:54:36 by rvaldes-          #+#    #+#             */
/*   Updated: 2021/11/22 12:54:37 by rvaldes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_loop(char const *s, unsigned int start, size_t len, char *p)
{
	int	i;

	i = 0;
	while (i < (int)len && s[i] != '\0')
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (s == NULL)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
	{
		p = malloc(1);
		if (p == NULL)
			return (0);
		p[0] = '\0';
		return (p);
	}
	p = malloc(len + 1);
	if (p == NULL)
		return (0);
	ft_loop(s, start, len, p);
	return (p);
}

void	join_aux(char *s1, char const *s2, char *p)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		p[i] = s2[j];
		j++;
		i++;
	}
	if (s2[j] == '\n')
	{
		p[i] = '\n';
		p[i + 1] = '\0';
	}
	else
		p[i] = '\0';
}

int	check_buff(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
