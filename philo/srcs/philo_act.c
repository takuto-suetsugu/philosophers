/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:41:29 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/04/01 11:06:21 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_think(t_act *act, int id)
{
	act->sleeping = 0;
	act->thinking = 1;
	mutex_printf(id, "is thinking", act->data);
}

void	philo_sleep(t_act *act, t_data *data, int id)
{
	act->eating = 0;
	act->sleeping = 1;
	mutex_printf(id, "is sleeping", data);
	act_specified_time(data->time_to_sleep, act);
}

void	philo_eat(t_act *act, t_data *data, int id)
{
	act->eating = 1;
	mutex_printf(id, "is eating", data);
	act->time_last_eat = get_ms();
	act_specified_time(data->time_to_eat, act);
	pthread_mutex_unlock(&(data->forks[id - 1]));
	if (id == data->num_of_philo)
		pthread_mutex_unlock(&(data->forks[0]));
	else
		pthread_mutex_unlock(&(data->forks[id]));
	act->hand_full = 0;
	act->eating_count++;
	if (act->eating_count == data->num_of_must_eat)
		act->finish_eat = 1;
}

void	philo_take_fork(t_act *act, t_data *data, int id)
{
	if (act->thinking == 1)
		act->thinking = 0;
	pthread_mutex_lock(&(data->forks[id - 1]));
	if (!act->finish_eat && !data->die)
		mutex_printf(id, "has taken a fork", data);
	if (data->num_of_philo == 1)
		return ;
	if (id == data->num_of_philo)
		pthread_mutex_lock(&(data->forks[0]));
	else
		pthread_mutex_lock(&(data->forks[id]));
	if (!act->finish_eat && !data->die)
		mutex_printf(id, "has taken a fork", data);
	act->hand_full = 1;
}

void	*philo_act(void *act_addr)
{
	t_act	*act;
	t_data	*data;
	int		id;

	act = act_addr;
	data = act->data;
	id = act->philo_id;
	if (id % 2 == 0)
		usleep((data->time_to_eat) * 0.5);
	philo_take_fork(act, data, id);
	while (!act->finish_eat && !data->die)
	{
		if (act->thinking == 1)
			philo_take_fork(act, data, id);
		else if (act->hand_full == 1)
			philo_eat(act, data, id);
		else if (act->eating == 1)
			philo_sleep(act, data, id);
		else if (act->sleeping == 1)
			philo_think(act, id);
	}
	return (NULL);
}
