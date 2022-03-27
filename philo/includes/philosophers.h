/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:36:21 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/27 12:59:54 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<pthread.h>
# include 	<string.h>
# include 	<sys/time.h>


typedef struct s_act {
	int				philo_id;
	int				left_hand;
	int				right_hand;
	int				eating;
	int				sleeping;
	int				thinking;
	struct s_data	*data;
}				t_act;
typedef struct s_data {
	int			num_of_philo;
	int			num_of_forks;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_must_eat;
	long long	start_time;
	int			finish;
	t_act		*act;
}				t_data;

/* ft_atoi.c */
long	ft_atoi(const char *str);

/* error.c */
void	ft_error(char *error_message);

/* philo_act.c */
void	*philo_act(void *argv);

/* data_init.c */
void	data_init(int argc, char **argv, t_data *data);

/* get_time.c */
long long	get_ll_time(void);

#endif