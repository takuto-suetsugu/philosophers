/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:36:21 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/25 16:21:37 by tsuetsug         ###   ########.fr       */
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

typedef struct s_act {
	int	left_hand;
	int	right_hand;
	int	eating;
	int	sleeping;
	int	thinking;
}				t_act;
typedef struct s_data {
	int			philo_id;
	int			num_of_philo;
	int			num_of_forks;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_must_eat;
	int			finish;
	t_act	act;
}				t_data;

/* ft_atoi.c */
long	ft_atoi(const char *str);

#endif