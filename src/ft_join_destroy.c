/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:59:17 by akhodara          #+#    #+#             */
/*   Updated: 2023/07/01 16:01:30 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_join_thread(t_ph *ph)
{
	int	i;

	i = (ph->data->num_philo - 1);
	while (i >= 0)
	{
		pthread_join(ph[i].thread, NULL);
		i--;
	}
}

void	ft_destroy_mutexs(t_data *data)
{
	int	i;

	i = (data->num_philo - 1);
	while (i >= 0)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i--;
	}
	pthread_mutex_destroy(&data->print_mutex);
}
