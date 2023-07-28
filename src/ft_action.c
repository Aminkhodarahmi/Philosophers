/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:59:02 by akhodara          #+#    #+#             */
/*   Updated: 2023/07/01 16:03:43 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_action_eat(t_ph *ph)
{
	pthread_mutex_lock(ph->fork_left);
	ft_print_action(ph, "fork");
	if (ph->fork_right != NULL)
	{
		pthread_mutex_lock(ph->fork_right);
		ft_print_action(ph, "fork");
		ft_print_action(ph, "eat");
		ph->lastime_eat = ft_get_time();
		usleep(ph->data->time_eat);
		pthread_mutex_unlock(ph->fork_right);
	}
	else
		ft_print_action(ph, "fork");
	pthread_mutex_unlock(ph->fork_left);
}

void	ft_action_sleep(t_ph *ph)
{
	ft_print_action(ph, "sleep");
	if (ph->data->death != 1)
		usleep(ph->data->time_sleep);
}

void	ft_action_think(t_ph *ph)
{
	ft_print_action(ph, "think");
}
