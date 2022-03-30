/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:41:29 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/30 10:45:42 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	act_specified_time(int time_to_act)
{
	long long	act_time;
	long long	start_time;
	long long	current_time;

	act_time = (long long)time_to_act;
	start_time = get_ms();
	current_time = get_ms();
	while (act_time > current_time - start_time)
	{
		current_time = get_ms();
		usleep(10);
	}
}

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
	act_specified_time(data->time_to_sleep);
}

void	philo_eat(t_act *act, t_data *data, int id)
{
	act->eating = 1;
	act->eating_count++;
	mutex_printf(id, "is eating", data);
	act_specified_time(data->time_to_eat);
	act->hand_full = 0;
	pthread_mutex_unlock(&(data->forks[id - 1]));
	if (id == data->num_of_philo)
		pthread_mutex_unlock(&(data->forks[0]));
	else
		pthread_mutex_unlock(&(data->forks[id]));
}

void	philo_take_fork(t_act *act, t_data *data, int id)
{
	act->hand_full = 1;
	pthread_mutex_lock(&(data->forks[id - 1]));
	mutex_printf(id, "has taken a fork", data);
	if (id == data->num_of_philo)
		pthread_mutex_lock(&(data->forks[0]));
	else
		pthread_mutex_lock(&(data->forks[id]));
	mutex_printf(id, "has taken a fork", data);
}

void*    philo_act(void *act_addr)
{
	t_act	*act;
	t_data	*data;
	int		id;

	act = act_addr;
	data = act->data;
	id = act->philo_id;
	if (id % 2 == 0)
		act_specified_time((data->time_to_eat) * 0.5);
	philo_take_fork(act, data, id);
	while (act != NULL)
	{
		if (act->thinking == 1)
		{
			act->thinking = 0;
			philo_take_fork(act, data, id);
		}
		else if (act->hand_full == 1)
		{
			philo_eat(act, data, id);
			if (act->eating_count == data->num_of_must_eat
				&& data->num_of_must_eat > 0)
				return (NULL);
		}
		else if (act->eating == 1)
			philo_sleep(act, data, id);
		else if (act->sleeping == 1)
			philo_think(act, id);
	}
	return (NULL);
}
