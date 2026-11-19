/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:17:52 by marvin            #+#    #+#             */
/*   Updated: 2024/02/26 15:17:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putnbr(int n)
{
	char	digit;

	if (n >= 10)
		putnbr(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

void	printnbr(int n)
{
	write(1, "nbr de move : ", 14);
	putnbr(n);
	write(1, "\n", 1);
}
