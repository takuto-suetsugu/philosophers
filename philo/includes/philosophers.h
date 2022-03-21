/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:36:21 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/21 16:41:14 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include   <errno.h>
# include   <fcntl.h>
# include	<pthread.h>

typedef struct s_data {
	int	num_of_philo;
	int	num_of_forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_must_eat;
	int	finish;
}				t_data;

#endif