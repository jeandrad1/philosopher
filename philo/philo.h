#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_philo
{
    int				id;
    int				left_fork;
    int				right_fork;
    int				eat_count;
    long long		last_eat;
    bool            dead;
    pthread_t		thread; 
    struct s_data	*data;
}					t_philo;