/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:59:11 by akhodara          #+#    #+#             */
/*   Updated: 2023/07/02 11:03:39 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	ft_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

long	ft_long_atoi(const char *str)
{
	long	r;
	long	c;

	c = 1;
	r = 0;
	while (ft_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			c = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		r = (r * 10) + ((*str++) - '0');
	return (r * c);
}

int	ft_ponter_isdigit(char *c)
{
	int	i;

	i = -1;
	while (c[++i])
	{
		if (c[i] < 48 || c[i] > 57)
			return (1);
	}
	return (0);
}

int	ft_convert_argument(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_ponter_isdigit(argv[i]) == 1)
			return (ft_error(2));
		if (ft_long_atoi(argv[i]) == 0)
			return (ft_error(1));
		i++;
	}
	return (0);
}
