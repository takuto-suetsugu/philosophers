/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:32:19 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/04/01 08:30:21 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	start_thread(t_data *data, t_act *act)
{
	int			i;
	pthread_t	thread;

	data->start_time = get_ms();
	i = 0;
	while (i < data->num_of_philo)
	{
		data->act[i].time_last_eat = get_ms();
		if (pthread_create(&(data->act[i].thread), NULL, philo_act,
				(void *)&(act[i])) != 0)
			ft_error("pthread_create is failed");
		pthread_create(&thread, NULL, monitor_death, &data->act[i]);
		pthread_detach(thread);
		i++;
	}
	if (data->num_of_must_eat != 0)
	{
		pthread_create(&thread, NULL, monitor_eating_count, &data->act[i]);
		pthread_detach(thread);
	}
}

void	end_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_join(data->act[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		pthread_mutex_destroy(&(data->act[i].finish_mutex));
		i++;
	}
	pthread_mutex_destroy(&(data->write));
	free(data->act);
	free(data->forks);
	free(data);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 5 && argc != 6)
		ft_error("argc is invalid");
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		ft_error("data is not allocated");
	data_init(argc, argv, data);
	start_thread(data, (data)->act);
	end_thread(data);
	return (0);
}
