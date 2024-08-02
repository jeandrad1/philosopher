#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# include <stdint.h>
# include <sys/time.h>

#define SUCCESS 1
#define FAILURE 0

// Table structure
typedef struct table
{
    int				            philo_count;
    int				            time_to_die;
    int				            time_to_eat;
    int				            time_to_sleep;
    int				            eat_count;
    long            			start_time;
    pthread_mutex_t             is_dead;    
    pthread_mutex_t				*forks;
    pthread_mutex_t				print;
    pthread_mutex_t				eat;
    pthread_t                   control;
}					t_table;

// Philosopher structure
typedef struct s_philo
{
    int				            id;
    pthread_mutex_t			    *left_fork;
    pthread_mutex_t	            *right_fork;
    int				            eat_count;
    long long	              	last_eat;
    pthread_t	               	thread;
    t_table	                    *table;

}	                t_philo;

// First parser function
bool    parse(int argc, char **argv);

// Initialize table function
bool    init_table(t_table *table, int argc, char **argv);

// Initialize all philosophers function
bool    init_all_philo(t_philo *philo, t_table *table);

// Init the threads
bool    create_philo_threads(t_philo *philo, t_table *table);

// Actions
void *philo_think (void *philosopher);
void *philo_eat(void *philosopher);
void *philo_sleep(void *philosopher);
void *philo_takes_fork(void *philosopher);

// Dinner ends
bool dinner_ends(t_philo *philo);

// Time functions
long time_milliseconds(void);

// Better sleep function
void *better_sleep(long time);

