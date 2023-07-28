/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:58:59 by akhodara          #+#    #+#             */
/*   Updated: 2023/07/01 16:04:08 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include "philo.h"

typedef struct s_data
{
	pthread_t		check_death;
	pthread_mutex_t	*forks;
	int				num_philo;
	_Atomic int		death;
	_Atomic int		all_eat;
	int				num_eat;
	int				exit;
	int				count;
	time_t			time_sleep;
	time_t			time_die;
	time_t			time_eat;
	time_t			t_init;
	pthread_mutex_t	print_mutex;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	_Atomic int		num_eat;
	t_data			*data;
	_Atomic time_t	lastime_eat;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	int				i;
}	t_ph;

int		ft_check_arguments(int argc, char **argv);
int		ft_convert_argument(char **argv);
int		ft_ponter_isdigit(char *c);
int		ft_error(int number);
void	ft_join_thread(t_ph *ph);
void	ft_destroy_mutexs(t_data *data);
void	ft_set_init(t_data *data, char **argv);
time_t	ft_get_time(void);
void	ft_init_mutex(t_data *data);
void	ft_init_philo(t_data *data, t_ph *ph);
void	ft_set_philo(t_data *data, t_ph *ph);
void	*ft_dinner(void *philo);
time_t	ft_time_prog(t_data *data);
void	*ft_check_death(void	*philo);
void	ft_action_eat(t_ph *ph);
void	ft_action_sleep(t_ph *ph);
void	ft_action_think(t_ph *ph);
long	ft_long_atoi(const char *str);
void	ft_set_thread(t_data *data, t_ph *ph);
void	ft_print_action(t_ph *ph, const char *action);

#endif
