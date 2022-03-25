/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:41:29 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/25 17:37:49 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void*    philo_act(void *argv)
{
	t_data	*data;

	data = argv;
	if (data->philo_id % 2 == 1 && data->act.sleeping == 0)
	{	
		printf("%d is sleeping\n", data->philo_id);
		data->act.sleeping = 1;
	}
	else if ((data->act.left_hand && data->act.right_hand) == 0
		&& data->act.sleeping == 0)
	{
		printf("%d has taken a fork\n", data->philo_id);
		data->act.left_hand = 1;
	}
	else if (data->act.left_hand == 1 && data->act.right_hand == 0)
	{
		printf("%d has taken a fork\n", data->philo_id);
		data->act.right_hand = 1;
	}
	else if (data->act.left_hand == 1 && data->act.right_hand == 1)
	{
		printf("%d is eating\n", data->philo_id);
		data->act.eating = 1;
	}
	else if (data->act.eating == 1)
	{
		printf("%d is sleeping\n", data->philo_id);
		data->act.left_hand = 0;
		data->act.right_hand = 0;
		data->act.eating = 0;
		data->act.sleeping = 1;
	}
	else if (data->act.eating == 1)
	{
		printf("%d is thinking\n", data->philo_id);
		data->act.sleeping = 0;
		data->act.thinking = 1;
	}
	return NULL;
}
