/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:23:01 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/19 00:50:21 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t	is_sep(char si, char c)
{
	if (si == c || si == '\0')
		return (1);
	return (0);
}

void	free_stuff(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	remplir_str(char *dest, char *src, char sep)
{
	size_t	i;

	i = 0;
	while (is_sep(src[i], sep) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

size_t	remplir_table(char **tab, char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (is_sep(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (is_sep(str[i + j], c) == 0)
				j++;
			tab[word] = malloc(sizeof(char) * (j + 1));
			remplir_str(tab[word], &str[i], c);
			if (!tab[word])
				return (1);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	char	*str;
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	str = (char *)s;
	while (str[i])
	{
		if (is_sep(str[i], c) == 0
			&& is_sep(str[i + 1], c) == 1)
			count++;
		i++;
	}
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	tab[count] = NULL;
	i = remplir_table(tab, str, c);
	if (i)
		free_stuff(tab);
	return (tab);
}
