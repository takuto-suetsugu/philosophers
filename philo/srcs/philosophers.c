/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:32:19 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/26 20:33:53 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	data_init(int argc, char **argv, t_data *data)
{
	int i;

	i = 0;
	data->num_of_philo = ft_atoi(argv[1]);
	data->num_of_philo = ft_atoi(argv[1]);
	data->num_of_forks = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_of_must_eat = ft_atoi(argv[5]);
	else
		data->num_of_must_eat = -1;
	data->act = memset(&data->act, 0, data->num_of_philo * sizeof(data->act));
	if (data->act == NULL)
		ft_error("act is not allocated");
	while (i++ < data->num_of_philo)
	{
		data->act[i].left_hand = 0;
		data->act[i].right_hand = 0;
		data->act[i].eating = 0;
		data->act[i].sleeping = 0;
		data->act[i].thinking = 0;
	}
}

void	start_thread(t_data *data)
{
	pthread_t	thread;
	int			philo_n;

	data = malloc(data->num_of_philo * sizeof(data));
	if (data == NULL)
		ft_error("act is not allocated");
	philo_n = 0;
	while (philo_n < data->num_of_philo)
	{
		data->act[philo_n].philo_id = philo_n;
		if (pthread_create(&thread, NULL, philo_act, &data->act[philo_n]) != 0)
			ft_error("pthread_create is failed");
		philo_n++;
	}
	pthread_join(thread, NULL);
}

int	main(int argc, char **argv)
{
	t_data			data;
	pthread_mutex_t	mutex;

	memset(&data, 0, sizeof(data));
	if (argc != 5 && argc != 6)
		ft_error("argc is invalid");
	pthread_mutex_init(&mutex, NULL);
	data_init(argc, argv, &data);
	start_thread(&data);
	pthread_mutex_destroy(&mutex);
	return (0);
}
