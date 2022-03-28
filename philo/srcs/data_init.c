/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 10:34:02 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/28 16:06:20 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_data(int argc, char **argv, t_data *data)
{
	int	i;

	memset(data, 0, sizeof(*data));
	data->num_of_philo = ft_atoi(argv[1]);
	data->num_of_forks = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_of_must_eat = ft_atoi(argv[5]);
	else
		data->num_of_must_eat = 0;
	i = 0;
	while (i < data->num_of_forks)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			ft_error("mutex is not init");
		i++;
	}
}

void	validate_rules(t_data *data)
{
	if (data->num_of_philo < 0)
		ft_error("num_of_philo is invalid");
	if (data->time_to_die < 0)
		ft_error("time_to_die is invalid");
	if (data->time_to_eat < 0)
		ft_error("time_to_eat is invalid");
	if (data->time_to_sleep < 0)
		ft_error("time_to_sleep is invalid");
	if (data->num_of_must_eat < 0)
		ft_error("num_of_must_eat is invalid");
}

void	init_act(t_data *data)
{
	int	i;

	data->act = malloc(sizeof(data) * data->num_of_philo);
	if (data->act == NULL)
		ft_error("act is not allocated");
	i = 0;
	while (i < data->num_of_philo)
	{
		data->act[i].data = data;
		data->act[i].initial_status = 1;
		data->act[i].left_hand = 0;
		data->act[i].right_hand = 0;
		data->act[i].eating = 0;
		data->act[i].eating_count = 0;
		data->act[i].sleeping = 0;
		data->act[i].thinking = 0;
		i++;
	}
}

void	data_init(int argc, char **argv, t_data *data)
{
	init_data(argc, argv, data);
	validate_rules(data);
	init_act(data);
}
