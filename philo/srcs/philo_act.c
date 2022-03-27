/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:41:29 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/27 11:10:10 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void*    philo_act(void *act_addr)
{
	t_act	*act;

	act = act_addr;
	while (act != NULL)
	{
		if (act->philo_id % 2 == 1 && act->sleeping == 0)
		{
			printf("%d is sleeping\n", act->philo_id);
			act->sleeping = 1;
		}
		else if ((act->left_hand && act->right_hand) == 0
			&& act->sleeping == 0)
		{
			printf("%d has taken a left fork\n", act->philo_id);
			act->left_hand = 1;
		}
		else if (act->left_hand == 1 && act->right_hand == 0)
		{
			printf("%d has taken a right fork\n", act->philo_id);
			act->right_hand = 1;
		}
		else if (act->left_hand == 1 && act->right_hand == 1)
		{
			printf("%d is eating\n", act->philo_id);
			act->eating = 1;
		}
		else if (act->eating == 1)
		{
			printf("%d is sleeping\n", act->philo_id);
			act->left_hand = 0;
			act->right_hand = 0;
			act->eating = 0;
			act->sleeping = 1;
		}
		else if (act->sleeping == 1)
		{
			printf("%d is thinking\n", act->philo_id);
			act->sleeping = 0;
			act->thinking = 1;
			return NULL;
		}
	}
	return NULL;
}
