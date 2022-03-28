/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:41:29 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/28 22:22:54 by tsuetsug         ###   ########.fr       */
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
		usleep(100);
	}
}

void	philo_think(t_act *act)
{
	act->sleeping = 0;
	act->thinking = 1;
	printf("%lld %d is thinking\n", get_ms(), act->philo_id);
}

void	philo_sleep(t_act *act, t_data *data)
{
	act->left_hand = 0;
	act->right_hand = 0;
	act->eating = 0;
	act->sleeping = 1;
	pthread_mutex_unlock(&(data->forks[act->philo_id - 1]));
	if (act->philo_id == data->num_of_philo)
		pthread_mutex_unlock(&(data->forks[0]));
	else
		pthread_mutex_unlock(&(data->forks[act->philo_id]));
	printf("%lld %d is sleeping\n", get_ms(), act->philo_id);
	act_specified_time(data->time_to_sleep);
}

void	philo_eat(t_act *act, t_data *data)
{
	act->eating = 1;
	act->eating_count++;
	printf("%lld %d is eating\n", get_ms(), act->philo_id);
	act_specified_time(data->time_to_eat);
}

void	philo_take_fork(t_act *act, t_data *data)
{
	act->right_hand = 1;
	pthread_mutex_lock(&(data->forks[act->philo_id - 1]));
	printf("%lld %d has taken a %d fork\n", get_ms(), act->philo_id, act->philo_id - 1);
	act->left_hand = 1;
	if (act->philo_id == data->num_of_philo)
		pthread_mutex_lock(&(data->forks[0]));
	else
		pthread_mutex_lock(&(data->forks[act->philo_id]));
	printf("%lld %d has taken a %d fork\n", get_ms(), act->philo_id, act->philo_id);
}

void*    philo_act(void *act_addr)
{
	t_act	*act;
	t_data	*data;

	act = act_addr;
	data = act->data;
	if (act->philo_id % 2 == 0)
		act_specified_time(200);
	while (act != NULL)
	{
		if (act->thinking == 1)
		{
			act->thinking = 0;
			philo_take_fork(act, data);
		}
		else if (act->right_hand == 0 && act->left_hand == 0)
			philo_take_fork(act, data);
		else if (act->eating == 0)
		{
			philo_eat(act, data);
			if (act->eating_count == data->num_of_must_eat
				&& data->num_of_must_eat > 0)
				return (NULL);
		}
		else if (act->eating == 1)
			philo_sleep(act, data);
		else if (act->sleeping == 1)
			philo_think(act);
	}
	return (NULL);
}
