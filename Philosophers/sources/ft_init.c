/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:02:14 by dfernan3          #+#    #+#             */
/*   Updated: 2025/04/01 15:12:00 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->table->nb_philos;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->table->nb_philos;
		philo->fork[1] = philo->id;
	}
}

t_philo	**init_philosophers(t_table *table)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(table->nb_philos * sizeof(t_philo));
	if (!philos)
		return (error_null("Error to create malloc!!", 0));
	i = 0;
	while (i < table->nb_philos)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (error_null("Error to create malloc!!", 0));
		if (pthread_mutex_init(&philos[i]->meal_time_lock, 0) != 0)
			return (error_null("Error to create mutex!!", 0));
		philos[i]->table = table;
		philos[i]->id = i;
		philos[i]->times_ate = 0;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

pthread_mutex_t	*init_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(table->nb_philos * sizeof(pthread_mutex_t));
	if (!forks)
		return (error_null("Error to create malloc!!", 0));
	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (error_null("Error to create mutex!!", 0));
		i++;
	}
	return (forks);
}

bool	init_global_mutex(t_table *table)
{
	table->fork_locks = init_forks(table);
	if (!table->fork_locks)
		return (false);
	if (pthread_mutex_init(&table->sim_stop_lock, 0) != 0)
		return (error_failure("Error to create mutex!!", table));
	if (pthread_mutex_init(&table->write_lock, 0) != 0)
		return (error_failure("Error to create mutex!!", table));
	return (true);
}

t_table	*init_table(int ac, char **av, int i)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (error_null("Error to create malloc!!", 0));
	table->nb_philos = char_integer(av[i++]);
	table->time_to_die = char_integer(av[i++]);
	table->time_to_eat = char_integer(av[i++]);
	table->time_to_sleep = char_integer(av[i++]);
	table->must_eat_count = -1;
	if (ac == 6)
		table->must_eat_count = char_integer(av[i]);
	table->philos = init_philosophers(table);
	if (!table->philos)
		return (NULL);
	if (!init_global_mutex(table))
		return (NULL);
	table->sim_stop = false;
	return (table);
}
