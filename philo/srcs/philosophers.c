/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:32:19 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/28 19:19:04 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	start_thread(t_data *data, t_act *act)
{
	pthread_t	thread;
	int			i;

	data->start_time = get_ms();
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_create(&thread, NULL, philo_act,
				(void *)&(act[i])) != 0)
			ft_error("pthread_create is failed");
		i++;
	}
	pthread_join(thread, NULL);
}

int	main(int argc, char **argv)
{
	t_data			data;

	if (argc != 5 && argc != 6)
		ft_error("argc is invalid");
	if (argv[5] && argv[5] == 0)
		return (0);
	data_init(argc, argv, &data);
	start_thread(&data, (&data)->act);
	return (0);
}
