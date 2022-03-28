/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:41:29 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/28 15:34:00 by tsuetsug         ###   ########.fr       */
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

void	philo_sleep(t_act *act, t_data *data)
{
	printf("%lld %d is sleeping\n", get_ms(), act->philo_id);
	act_specified_time(data->time_to_sleep);
	act->left_hand = 0;
	act->right_hand = 0;
	act->eating = 0;
	act->sleeping = 1;
}

void	philo_eat(t_act *act, t_data *data)
{
	printf("%lld %d is eating\n", get_ms(), act->philo_id);
	act_specified_time(data->time_to_eat);
	act->eating = 1;
	act->eating_count++;
}

void*    philo_act(void *act_addr)
{
	t_act	*act;
	t_data	*data;

	act = act_addr;
	data = act->data;
	if (act->philo_id % 2 == 1)
		usleep(200);
	printf("%lld %d has taken a fork\n", get_ms(), act->philo_id);
	act->left_hand = 1;
	while (act != NULL)
	{
		if (act->thinking == 1)
		{
			printf("%lld %d has taken a fork\n", get_ms(), act->philo_id);
			act->left_hand = 1;
			act->thinking = 0;
		}
		else if (act->left_hand == 1 && act->right_hand == 0)
		{
			printf("%lld %d has taken a fork\n", get_ms(), act->philo_id);
			act->right_hand = 1;
		}
		else if (act->left_hand == 1 && act->right_hand == 1
			&& act->eating == 0)
		{
			philo_eat(act, data);
			if (act->eating_count == data->num_of_must_eat
				&& data->num_of_must_eat > 0)
				return (NULL);
		}
		else if (act->eating == 1)
			philo_sleep(act, data);
		else if (act->sleeping == 1)
		{
			printf("%lld %d is thinking\n", get_ms(), act->philo_id);
			act->sleeping = 0;
			act->thinking = 1;
		}
	}
	return (NULL);
}
