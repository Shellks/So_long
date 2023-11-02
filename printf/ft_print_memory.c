/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:28:09 by acarlott          #+#    #+#             */
/*   Updated: 2022/12/09 09:58:40 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_memory(unsigned long nbr)
{
	unsigned int		i;
	unsigned long int	nb;
	int					count;
	char				*base;

	nb = nbr;
	count = 0;
	base = "0123456789abcdef";
	i = 0;
	if (nb > 15)
		count += ft_print_memory(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}
