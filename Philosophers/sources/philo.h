/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:39:33 by dfernan3          #+#    #+#             */
/*   Updated: 2025/04/01 16:49:35 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RANGE_NUM "INVALID NUMBER!! must be between 1 and 2147483647.\n"
# define RANGE_NUM2 "INVALID NUMBER!! must be between 0 and 2147483647\n"
# define NUM_PHILOS "INVALID NUMBER OF PHILOS!!! must be between 1 and 200\n"
# define NEGATIVE_NUMBER "INVALID NUMBER!! must be bigger than 0\n"

# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define GREY "\033[37m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

# define MAX_PHILOS 200

typedef struct s_philo	t_philo;

typedef struct s_table
{
	time_t				start_time;
	unsigned int		nb_philos;
	pthread_t			grim_reaper;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	int					must_eat_count;
	pthread_mutex_t		sim_stop_lock;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		*fork_locks;
	bool				sim_stop;
	t_philo				**philos;
}						t_table;

typedef struct s_philo
{
	pthread_t			thread;
	unsigned int		id;
	unsigned int		times_ate;
	unsigned int		fork[2];
	pthread_mutex_t		meal_time_lock;
	time_t				last_meal;
	t_table				*table;
}						t_philo;

typedef enum e_status
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	GOT_FORK_1 = 4,
	GOT_FORK_2 = 5
}						t_status;

t_table					*init_table(int ac, char **av, int i);
bool					is_valid(int ac, char **av);
int						ft_error(char *message, int type_exit);
void					*free_table(t_table *table);
int						error_failure(char *str, t_table *table);
void					destroy_mutexes(t_table *table);
void					*error_null(char *str, t_table *table);
t_table					*init_table(int ac, char **av, int i);
time_t					get_time_in_ms(void);
void					sim_start_delay(time_t start_time);
bool					has_simulation_stopped(t_table *table);
void					write_status(t_philo *philo, bool reaper_report,
							t_status status);
void					write_outcome(t_table *table);
void					*philosopher(void *data);
void					philo_sleep(t_table *table, time_t sleep_time);
void					*grim_reaper(void *data);
int						char_integer(char *str);

#endif