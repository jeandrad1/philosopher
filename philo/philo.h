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
    int				id;
    int				left_fork;
    int				right_fork;
    int				eat_count;
    long long		last_eat;
    bool            is_dead;
    pthread_t		thread; 
}					t_philo;

// Error exit function
void   error_exit(char *str);

// First parser function
void    parse(int argc, char **argv);
