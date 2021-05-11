/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:15:56 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/10 19:16:02 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_u64	ft_power(t_u64 base, t_u64 exponent)
{
	if (exponent == 0)
		return (1);
	return (base * ft_power(base, exponent - 1));
}