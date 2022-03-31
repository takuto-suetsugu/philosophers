/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:36:21 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/31 15:58:10 by tsuetsug         ###   ########.fr       */
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
	int				hand_full;
	int				eating;
	int				eating_count;
	int				sleeping;
	int				thinking;
	int				finish;
	long long		time_last_eat;
	struct s_data	*data;
	pthread_mutex_t	finish_mutex;
	pthread_t		thread;
}				t_act;
typedef struct s_data {
	long			num_of_philo;
	long			num_of_forks;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_of_must_eat;
	long long		start_time;
	int				all_finish;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	t_act			*act;
}				t_data;

/* philo_utils.c */
long	ft_atoi(const char *str);
void    mutex_printf(int id, char *action, t_data *data);

/* error.c */
void	ft_error(char *error_message);

/* philo_act.c */
void	*philo_act(void *argv);

/* data_init.c */
void	data_init(int argc, char **argv, t_data *data);

/* get_time.c */
void	act_specified_time(int time_to_act, t_act *act);
long long	get_ms(void);

/* monitor.c */
void*    monitor_eating_count(void *act_addr);
void*    monitor_death(void *act_addr);

#endif