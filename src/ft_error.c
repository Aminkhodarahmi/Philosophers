/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:59:08 by akhodara          #+#    #+#             */
/*   Updated: 2023/07/01 16:02:29 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_error(int number)
{
	if (number == 0)
	{
		printf("please insert at least 4 arguments!\n");
	}
	if (number == 1)
		printf("Error 1 - Accepted values above '0' !\n");
	if (number == 2)
		printf("invalid!\n");
	if (number == 3)
		printf("malloc error allocating!\n");
	if (number == 4)
		printf("excessive number of arguments!\n");
	return (1);
}
