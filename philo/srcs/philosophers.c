/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:32:19 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/21 16:45:40 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "../includes/philosphers.h"

void	data_init(char **argv, t_data data)
{
	num_of_philo;
	num_of_forks;
	time_to_die;
	time_to_eat;
	time_to_sleep;
	num_of_must_eat;
}

int	philosphers(int argc, char **argv)
{
	t_data	data;

	if (argc != (4 || 5))
		ft_error("argc is invalid");
	data_init(argv, &data);
	return (0);
}