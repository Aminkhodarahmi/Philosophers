/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:59:14 by akhodara          #+#    #+#             */
/*   Updated: 2023/07/01 16:08:32 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_set_init(t_data *data, char **argv)
{
	int	i;

	i = -1;
	data->num_philo = ft_long_atoi(argv[1]);
	data->forks = (pthread_mutex_t *) malloc
		(sizeof (pthread_mutex_t) * data->num_philo);
	data->death = 0;
	data->time_die = ft_long_atoi(argv[2]) * 1000;
	data->time_eat = ft_long_atoi(argv[3]) * 1000;
	data->time_sleep = ft_long_atoi(argv[4]) * 1000;
	data->all_eat = 0;
	data->num_eat = -1;
	data->count++;
	if (argv[5])
		data->num_eat = ft_long_atoi(argv[5]);
	data->t_init = ft_get_time();
	pthread_mutex_init(&data->print_mutex, NULL);
	while (++i < data->num_philo)
		pthread_mutex_init(&data->forks[i], NULL);
}

void	ft_set_philo(t_data *data, t_ph *ph)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		ft_init_philo(data, &ph[i]);
		ph[i].id = i + 1;
		ph[i].fork_left = &data->forks[i];
		if (data->num_philo > 1)
		{
			if (i + 1 == data->num_philo)
			{
				ph[i].fork_left = &data->forks[0];
				ph[i].fork_right = &data->forks[i];
			}
			else
				ph[i].fork_right = &data->forks[i + 1];
		}
		else
			ph[i].fork_right = NULL;
		i++;
	}
	i = -1;
	while (++i < data->num_philo)
		pthread_create(&ph[i].thread, NULL, ft_dinner, &ph[i]);
}

void	ft_init_philo(t_data *data, t_ph *ph)
{
	data->count = 0;
	ph->num_eat = 0;
	ph->data = data;
	ph->lastime_eat = ft_get_time();
}
