/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:46:41 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/04/01 17:43:57 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	ft_atoi(const char *str)
{
	long	res;
	long	minus;

	minus = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		ft_error("argv is minus");
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * minus);
}

void	mutex_printf(int id, char *action, t_data *data)
{
	pthread_mutex_lock(&(data->write));
	printf("%lld %d %s\n", get_ms(), id, action);
	pthread_mutex_unlock(&(data->write));
}
