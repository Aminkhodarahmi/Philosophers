/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:59:20 by akhodara          #+#    #+#             */
/*   Updated: 2023/07/01 16:01:14 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

void	ft_print_action(t_ph *ph, const char *action)
{
	pthread_mutex_lock(&ph->data->print_mutex);
	if (ph->data->death != 1)
	{
		printf("%lu philo %d", ft_time_prog(ph->data), ph->id);
		if (ft_strcmp(action, "fork") == 0)
			printf(" has taken a fork\n");
		else if (ft_strcmp(action, "eat") == 0)
			printf(" is eating\n");
		else if (ft_strcmp(action, "sleep") == 0)
			printf(" is sleeping\n");
		else if (ft_strcmp(action, "think") == 0)
			printf(" is thinking\n");
		else if (ft_strcmp(action, "dead") == 0)
		{
			printf(" died\n");
			ph->data->death = 1;
		}
		else
			printf(" unknown action\n");
	}
	pthread_mutex_unlock(&ph->data->print_mutex);
}
