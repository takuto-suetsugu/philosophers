/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:17:41 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/04/01 09:20:06 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	act_specified_time(int time_to_act, t_act *act)
{
	long long	act_time;
	long long	start_time;
	long long	current_time;

	act_time = (long long)time_to_act;
	start_time = get_ms();
	current_time = get_ms();
	while (act_time > current_time - start_time && act->finish_eat == 0)
	{
		current_time = get_ms();
		usleep(10);
	}
}

long long	get_ms(void)
{
	struct timeval	time;
	long long		ll_time;

	gettimeofday(&time, NULL);
	ll_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ll_time);
}
