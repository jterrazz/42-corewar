/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:34:27 by fbonnin           #+#    #+#             */
/*   Updated: 2017/05/15 13:56:05 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	**ft_alloc_words(char const *s, char c)
{
	char	**result;
	int		i_s;
	int		nb_words;

	i_s = 0;
	nb_words = 0;
	while (s[i_s] != 0)
	{
		if (s[i_s] != c && (i_s == 0 || s[i_s - 1] == c))
			nb_words++;
		i_s++;
	}
	result = malloc((nb_words + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result[nb_words] = NULL;
	return (result);
}

static int	ft_free_result(char **result, int i_word)
{
	i_word--;
	while (i_word >= 0)
	{
		free(result[i_word]);
		i_word--;
	}
	free(result);
	return (-1);
}

static int	ft_alloc_letters(char const *s, char c, char **result)
{
	int i_s;
	int i_word;
	int len_word;

	i_s = 0;
	i_word = 0;
	while (s[i_s] != 0)
	{
		if (s[i_s] != c)
		{
			len_word = 0;
			while (s[i_s] != c && s[i_s] != 0)
			{
				i_s++;
				len_word++;
			}
			result[i_word] = ft_strnew(len_word);
			if (result[i_word] == NULL)
				return (ft_free_result(result, i_word));
			i_word++;
		}
		else
			i_s++;
	}
	return (0);
}

static void	ft_copy(char const *s, char c, char **result)
{
	int i_s;
	int i_word;
	int i_letter;

	i_s = 0;
	i_word = 0;
	while (s[i_s] != 0)
	{
		if (s[i_s] != c)
		{
			i_letter = 0;
			while (s[i_s] != c && s[i_s] != 0)
			{
				result[i_word][i_letter] = s[i_s];
				i_s++;
				i_letter++;
			}
			i_word++;
		}
		else
			i_s++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char **result;

	if (s == NULL)
		return (NULL);
	result = ft_alloc_words(s, c);
	if (result == NULL)
		return (NULL);
	if (ft_alloc_letters(s, c, result) == -1)
		return (NULL);
	ft_copy(s, c, result);
	return (result);
}
