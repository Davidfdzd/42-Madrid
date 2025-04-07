/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:02:39 by dfernan3          #+#    #+#             */
/*   Updated: 2025/04/01 15:14:16 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *str, char *color)
{
	printf("%s%ld %d %s%s\n", color, get_time_in_ms()
		- philo->table->start_time, philo->id + 1, str, RESET);
}

void	write_status(t_philo *philo, bool reaper_report, t_status status)
{
	pthread_mutex_lock(&philo->table->write_lock);
	if (has_simulation_stopped(philo->table) == true && reaper_report == false)
	{
		pthread_mutex_unlock(&philo->table->write_lock);
		return ;
	}
	if (status == DIED)
		print_status(philo, "died", RED);
	else if (status == EATING)
		print_status(philo, "is eating", GREEN);
	else if (status == SLEEPING)
		print_status(philo, "is sleeping", YELLOW);
	else if (status == THINKING)
		print_status(philo, "is thinking", CYAN);
	else if (status == GOT_FORK_1 || status == GOT_FORK_2)
		print_status(philo, "has taken a fork", WHITE);
	pthread_mutex_unlock(&philo->table->write_lock);
}
