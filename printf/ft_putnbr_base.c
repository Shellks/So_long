/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:37:36 by acarlott          #+#    #+#             */
/*   Updated: 2022/12/09 09:58:13 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_base(unsigned int nbr, char str)
{
	unsigned int		i;
	unsigned int		nb;
	int					count;
	char				*base;

	nb = nbr;
	count = 0;
	i = 0;
	if (str == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb < 0)
		nb = 4294967295 + nbr;
	if (nb > 15)
		count += ft_putnbr_base(nb / 16, str);
	count += ft_putchar(base[nb % 16]);
	return (count);
}
