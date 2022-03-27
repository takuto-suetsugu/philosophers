/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:41:29 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/27 13:14:10 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_sleep(t_act *act, t_data *data)
{
	printf("%lld %d is sleeping\n", get_ll_time(), act->philo_id);
	act->sleeping = 1;
	usleep(data->time_to_sleep);
}

void	philo_eat(t_act *act, t_data *data)
{
	printf("%lld %d is eating\n", get_ll_time(), act->philo_id);
	act->eating = 1;
	usleep(data->time_to_eat);
}

void*    philo_act(void *act_addr)
{
	t_act	*act;
	t_data	*data;

	act = act_addr;
	data = act->data;
	while (act != NULL)
	{
		if (act->philo_id % 2 == 1 && act->sleeping == 0)
		{
			philo_sleep(act, data);
			usleep(200);
		}
		else if (act->left_hand == 0 && act->sleeping == 0)
		{
			printf("%lld %d has taken a fork\n", get_ll_time(), act->philo_id);
			act->left_hand = 1;
		}
		else if (act->left_hand == 1 && act->right_hand == 0)
		{
			printf("%lld %d has taken a fork\n", get_ll_time(), act->philo_id);
			act->right_hand = 1;
		}
		else if (act->left_hand == 1 && act->right_hand == 1
			&& act->eating == 0)
		{
			philo_eat(act, data);
		}
		else if (act->eating == 1)
		{
			act->left_hand = 0;
			act->right_hand = 0;
			act->eating = 0;
			philo_sleep(act, data);
		}
		else if (act->sleeping == 1)
		{
			printf("%lld %d is thinking\n", get_ll_time(), act->philo_id);
			act->sleeping = 0;
			act->thinking = 1;
			return NULL;
		}
	}
	return NULL;
}
