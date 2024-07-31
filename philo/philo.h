#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# include <stdint.h>
# include <sys/time.h>

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
    t_philo                    *data;
}					t_philo;


// Error exit function
void   error_exit(char *str);

// First parser function
void    parse(int argc, char **argv);
