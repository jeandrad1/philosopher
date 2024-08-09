/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:41:14 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/09 16:05:44 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0

// Define the structure of the table and the philosopher
typedef struct table	t_table;
typedef struct s_philo	t_philo;

// Table structure
typedef struct table
{
	int					philo_count;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					eat_max;
	long				start_time;
	bool				stop;
	pthread_mutex_t		is_dead;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	pthread_mutex_t		eat;
	pthread_mutex_t		ready;
	pthread_t			control;
	t_philo				*philo;
}						t_table;

// Philosopher structure
typedef struct s_philo
{
	int					id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	int					eat_count;
	long				last_eat;
	pthread_t			thread;
	t_table				*table;

}						t_philo;

// Utils
void					*ft_calloc(size_t num, size_t size);
int						ft_atoi(const char *str);
int						ft_strcmp(const char *str1, const char *str2);

// First parser function
bool					parse(int argc, char **argv);

// Initialize table function
bool					init_table(t_table *table, int argc, char **argv);

// Initialize all philosophers function
bool					init_all_philo(t_philo *philo, t_table *table);

// Init the threads
bool					create_philo_threads(t_philo *philo, t_table *table);

// Actions
bool					philo_think(t_philo *philosopher);
bool					philo_eat(t_philo *philosopher);
bool					philo_sleep(t_philo *philosopher);
bool					philo_takes_fork(t_philo *philosopher);

// Control function
void					*control(void *table);

// Dinner ends
bool					dinner_ends(t_philo *philo, t_table *table);

// Time functions
long					time_milliseconds(void);

// Better sleep function
void					*better_sleep(long time);

// Protected
bool					protected_print(t_philo *philo, char *str);
int						protected_death(t_philo *philo);

// Death
void					ft_free(t_table *table);