/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:16:38 by tmoirand          #+#    #+#             */
/*   Updated: 2024/02/21 17:00:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	tnbr(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_min(void)
{
	char	*min;

	min = ft_strdup("-2147483648");
	if (min == NULL)
		return (NULL);
	return (min);
}

void	ft_itoa_set(int n, char *toa, int nbr)
{
	if (n < 0)
	{
		toa[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		toa[--nbr] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*toa;
	int		nbr;

	nbr = tnbr(n);
	toa = malloc(sizeof(char) * (nbr + 1));
	if (toa == NULL)
		return (NULL);
	toa[nbr] = '\0';
	if (n == 0)
	{
		toa[0] = '0';
		return (toa);
	}
	if (n == -2147483648)
	{
		free(toa);
		return (ft_itoa_min());
	}
	ft_itoa_set(n, toa, nbr);
	return (toa);
}
