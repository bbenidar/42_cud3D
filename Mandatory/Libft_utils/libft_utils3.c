/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:13:03 by moudrib           #+#    #+#             */
/*   Updated: 2023/08/05 11:02:58 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_atoi(const char *str)
{
	ssize_t		i;
	ssize_t		sign;
	ssize_t		res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sign);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_lenword(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free (arr[i]);
	free (arr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;

	i = 0;
	if (!s)
		return (0);
	str = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			str[i] = ft_substr(s, 0, ft_lenword(s, c));
			if (!str[i])
				return (ft_free_arr(str));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	str[i] = 0;
	return (str);
}
