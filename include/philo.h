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
    unsigned int				philo_count;
    unsigned int				time_to_die;
    unsigned int				time_to_eat;
    unsigned int				time_to_sleep;
    unsigned int				eat_count;
    bool                        is_dead;
    pthread_mutex_t				*forks;
    pthread_mutex_t				print;
    pthread_mutex_t				dead;
    pthread_mutex_t				eat;
}					t_table;

// Philosopher structure
typedef struct s_philo
{
    unsigned int				id;
    unsigned int				left_fork;
    unsigned int				right_fork;
    unsigned int				eat_count;
    long long	              	last_eat;
    bool                        is_dead;
    pthread_t	               	thread;
}					t_philo;

// First parser function
bool    parse(int argc, char **argv);

// Initialize table function
bool init_table(t_table *table, int argc, char **argv);

