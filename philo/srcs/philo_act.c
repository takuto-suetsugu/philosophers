/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:41:29 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/25 16:32:33 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "../includes/philosphers.h"

void    philo_act(t_data data)
{
	if (data->philo_id % 2 == 1 && data->act.sleeping == 0)
	{	
		printf("%d is sleeping");
		data->act.sleeping = 1;
	}
	else if ((data->act.left_hand && data->act.right_hand) == 0
		&& data->act.sleeping == 0)
	{
		printf("%d has taken a fork");
		data->act.left_hand = 1;
	}
	else if (data->act.left_hand == 1 && data->act.right_hand == 0)
	{
		printf("%d has taken a fork");
		data->act.right_hand = 1;
	}
	else if (data->act.left_hand == 1 && data->act.right_hand == 1)
	{
		printf("%d is eating");
		data->act.eating = 1;
	}
	else if (data->act.eatings == 1)
	{
		printf("%d is sleeping");
		data->act.left_hand = 0;
		data->act.right_hand = 0;
		data->act.eating = 0;
		data->act.sleeping = 1;
	}
	else if (data->act.eatings == 1)
	{
		printf("%d is thinking");
		data->act.sleeping = 0;
		data->act.thinking = 1;
	}
}