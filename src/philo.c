/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:59:28 by akhodara          #+#    #+#             */
/*   Updated: 2023/07/01 16:00:22 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	validate_arguments(int argc, char **argv)
{
	if (argc > 6)
		return (ft_error(4));
	if (argc < 5)
		return (ft_error(0));
	if (ft_convert_argument(argv) == 1)
	{
		printf("Invalid arguments.\n");
		return (1);
	}
	return (0);
}

int	sub_main(t_ph *ph)
{
	pthread_t	check_death_thread;

	if (pthread_create(&check_death_thread, NULL, ft_check_death, ph) != 0)
	{
		printf("error in create check_death thread.\n");
		return (1);
	}
	if (pthread_join(check_death_thread, NULL) != 0)
	{
		printf("error in join check_death thread.\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_ph		*ph;
	t_data		data;

	if (validate_arguments(argc, argv) == 1)
		return (1);
	ft_set_init(&data, argv);
	ph = (t_ph *)malloc(sizeof(t_ph) * ft_long_atoi(argv[1]));
	if (ph == NULL)
	{
		printf("error in Memory allocat\n");
		return (1);
	}
	ft_set_philo(&data, ph);
	if (sub_main(ph) == 1)
		return (1);
	ft_join_thread(ph);
	ft_destroy_mutexs(&data);
	free(ph);
	free(data.forks);
	return (0);
}
