/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:17:41 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/27 12:17:55 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long long	get_ll_time(void)
{
	struct timeval	time;
	long long		ll_time;

	gettimeofday(&time, NULL);
	ll_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ll_time);
}
