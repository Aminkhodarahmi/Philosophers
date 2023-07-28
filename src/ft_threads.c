/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:59:23 by akhodara          #+#    #+#             */
/*   Updated: 2023/07/03 14:59:56 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_sub_dinner(t_ph *ph)
{
	ph->num_eat++;
	if (ph->data->num_eat != -1 && ph->data->num_eat == ph->num_eat)
	{
		ph->data->all_eat++;
		return (1);
	}
	ft_action_sleep(ph);
	ft_action_think(ph);
	return (0);
}

void	*ft_dinner(void *philo)
{
	t_ph	*ph;

	ph = (t_ph *) philo;
	if (ph->id % 2 == 0)
		usleep(130);
	while (ph->data->death == 0)
	{
		ft_action_eat(ph);
		if (ph->fork_right != NULL)
		{
			if (ft_sub_dinner(ph))
				return (NULL);
		}
		else
			usleep(ph->data->time_die);
	}
	return (NULL);
}
