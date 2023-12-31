/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:16:08 by bbenidar          #+#    #+#             */
/*   Updated: 2023/09/12 22:44:28 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	else
	{
		if (n < 0)
		{
			n = n * -1;
			i++;
		}
		while (n > 9)
		{
			n = n / 10;
			i++;
		}
		return (i);
	}
}

static int	sign(char *p, int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		p[i] = '-';
		p[++i] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		p[i] = '-';
		n = n * -1;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	int		len;

	i = 0;
	len = ft_intlen(n);
	p = (char *)malloc(sizeof(*p) * (len + 1));
	if (!p)
		return (0);
	p[len] = '\0';
	n = sign(p, n);
	while (n > 9)
	{
		p[len - 1] = (n % 10) + '0';
		len--;
		n = n / 10;
	}
	if (n <= 9)
		p[len - 1] = n + '0';
	return (p);
}
