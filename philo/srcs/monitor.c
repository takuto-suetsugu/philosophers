/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 07:58:04 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/04/01 11:31:09 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*monitor_eating_count(void *act_addr)
{
	t_act	*act;
	t_data	*data;

	act = act_addr;
	data = act->data;
	while (act->finish_eat)
	{
		pthread_mutex_lock(&(data->finish_mutex));
		if (data->num_of_must_eat == act->eating_count)
			act->finish_eat = 1;
		pthread_mutex_unlock(&(data->finish_mutex));
	}
	return (NULL);
}

void	*monitor_death(void *act_addr)
{
	t_act		*act;
	t_data		*data;
	int			id;
	long long	now;

	act = act_addr;
	data = act->data;
	id = act->philo_id;
	while (!act->finish_eat && !data->die)
	{
		now = get_ms();
		if (now - act->time_last_eat > data->time_to_die)
		{
			//pthread_mutex_lock(&(data->finish_mutex));
			data->die = 1;
			mutex_printf(id, "died", data);
			//pthread_mutex_unlock(&(data->finish_mutex));
		}
	}
	return (NULL);
}
