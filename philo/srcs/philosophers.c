/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:32:19 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/25 17:39:30 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	data_init(char **argv, t_data *data)
{
	data->philo_id = 0;
	data->num_of_philo = ft_atoi(argv[1]);
	data->num_of_philo = ft_atoi(argv[1]);
	data->num_of_forks = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->num_of_must_eat = ft_atoi(argv[5]);
	data->act.left_hand = 0;
	data->act.right_hand = 0;
	data->act.eating = 0;
	data->act.sleeping = 0;
	data->act.thinking = 0;
}

void	start_thread(t_data *data)
{
	pthread_t	thread;
	void		*retval;
	int			philo_n;

	philo_n = 0;
	while (philo_n < data->num_of_philo)
	{
		data->philo_id = philo_n;
		if (pthread_create(&thread, NULL, philo_act, data) != 0)
			ft_error("pthread_create is failed");
		philo_n++;
	}
	pthread_join(thread, &retval);
}

int	main(int argc, char **argv)
{
	t_data			data;
	pthread_mutex_t	mutex;

	if (argc != 5 && argc != 6)
		ft_error("argc is invalid");
	pthread_mutex_init(&mutex, NULL);
	data_init(argv, &data);
	start_thread(&data);
	pthread_mutex_destroy(&mutex);
	return (0);
}