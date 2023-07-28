/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:59:05 by akhodara          #+#    #+#             */
/*   Updated: 2023/07/01 16:02:44 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_sub_check_death(t_data *data)
{
	if (data->all_eat == data->num_philo)
	{
		data->death = 1;
		return (1);
	}
	return (0);
}

void	*ft_check_death(void	*philo)
{
	t_ph	*ph;
	int		i;

	ph = (t_ph *)philo;
	while (!ph->data->death)
	{
		i = ph->data->num_philo - 1;
		while (i >= 0)
		{
			ph->i = i;
			usleep(100);
			if ((ft_get_time() - ph->lastime_eat) >= ph->data->time_die
				&& ph->data->num_eat != ph->num_eat)
				ft_print_action(ph, "dead");
			if (ft_sub_check_death(ph->data))
				break ;
			i--;
		}
		usleep(ph->data->time_die);
	}
	return (NULL);
}
