/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:35:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/07 19:42:18 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int protected_death(t_philo *philo)
{
    pthread_mutex_lock(&philo->table->is_dead);
    if (philo->table->stop == true)
    {                
        pthread_mutex_unlock(&philo->table->is_dead);
        return 1;
    }
    pthread_mutex_unlock(&philo->table->is_dead);
    return 0;
}

bool protected_print(t_philo *philo, char *str)
{
    long time;

    if(protected_death(philo))
        return false;    
    time = time_milliseconds() - philo->table->start_time;
    pthread_mutex_lock(&philo->table->print);
    if(protected_death(philo))
        return false;    
    printf("\n%ld Philosopher %d %s\n", time, philo->id, str);
    pthread_mutex_unlock(&philo->table->print);
    return true;
}
    
bool philo_takes_fork(t_philo *philo)
{
    if (philo->id % 2 == 0)
        usleep(5); 

    if(protected_death(philo))
        return false;    
    pthread_mutex_lock(philo->left_fork);
    protected_print(philo, "has taken left fork");
    pthread_mutex_lock(philo->right_fork);
    protected_print(philo, "has taken right fork");
    
    return true;
}

bool philo_eat(t_philo *philo)
{
    //pthread_mutex_lock(&philo->table->eat);
    
    if(protected_death(philo))
        return false;    
    protected_print(philo, "is eating");
    philo->last_eat = (time_milliseconds() - philo->table->start_time);
    philo->eat_count++;
    //pthread_mutex_unlock(&philo->table->eat);
    usleep(philo->table->time_to_eat * 1000);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);


    return true;
}

bool philo_sleep(t_philo *philo)
{
    if(protected_death(philo))
        return false;    
    protected_print(philo, "is sleeping");
    usleep(philo->table->time_to_sleep);
    return true;
}
bool philo_think (t_philo *philo)
{
    if(protected_death(philo))
        return false;    
    protected_print(philo, "is thinking");
    usleep(1000);
    return true;
}



