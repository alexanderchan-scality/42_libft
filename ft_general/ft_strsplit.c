/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan <achan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:37:57 by achan             #+#    #+#             */
/*   Updated: 2016/12/02 11:23:09 by achan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_general.h"

static size_t	wrd_cnt(char const *s, char c)
{
	size_t	i;
	size_t	cnt;
	int		w_flag;

	i = 0;
	cnt = 0;
	w_flag = 1;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (w_flag)
				cnt++;
			w_flag = 0;
		}
		else
			w_flag = 1;
		i++;
	}
	return (cnt);
}

static char		**wrd_split(char **list, char const *str, char c)
{
	char	*word;
	int		w_strt;
	int		w_len;
	int		ind;

	ind = 0;
	while (*str)
	{
		if (*str != c)
		{
			w_len = 0;
			while (str[w_len] && str[w_len] != c)
				w_len++;
			word = (char *)malloc(sizeof(char) * (w_len + 1));
			w_strt = 0;
			while (w_strt < w_len)
				word[w_strt++] = *str++;
			word[w_len] = '\0';
			list[ind] = word;
			ind++;
		}
		else
			str++;
	}
	return (list);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	word_cnt;
	char	**word_lst;

	if (!s)
		return (NULL);
	word_cnt = wrd_cnt(s, c);
	if (!(word_lst = (char **)malloc(sizeof(char *) * (word_cnt + 1))))
		return (NULL);
	word_lst[word_cnt] = 0;
	word_lst = wrd_split(word_lst, s, c);
	return (word_lst);
}
