/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:35:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/08 11:35:31 by jeandrad         ###   ########.fr       */
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

    
    if(protected_death(philo) && ft_strcmp(str, "died") != 0)
        return false; 
    time = time_milliseconds() - philo->table->start_time;    
    
    if(protected_death(philo))
        return false;
    
    pthread_mutex_lock(&philo->table->print);
    if(protected_death(philo) && ft_strcmp(str, "died") != 0)
    {
        pthread_mutex_unlock(&philo->table->print);
        return false;
    }
    printf("\n%ld Philosopher %d %s\n", time, philo->id, str);
    pthread_mutex_unlock(&philo->table->print);
    return true;
}
    
bool philo_takes_fork(t_philo *philo)
{
    if(protected_death(philo))
        return false;    
    pthread_mutex_lock(philo->left_fork);
    protected_print(philo, "has taken left fork");
    if (protected_death(philo))
    {
        pthread_mutex_unlock(philo->left_fork);
        return false;    
    }
    pthread_mutex_lock(philo->right_fork);
    protected_print(philo, "has taken right fork");
    if (protected_death(philo))
    {
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        return false;    
    }
    
    return true;
}

bool philo_eat(t_philo *philo)
{
    //pthread_mutex_lock(&philo->table->eat);
    
    if(protected_death(philo))
    {
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        return false;    
    }
    protected_print(philo, "is eating");
    pthread_mutex_lock(&philo->table->eat);
    philo->last_eat = (time_milliseconds() - philo->table->start_time);
    philo->eat_count++;
    pthread_mutex_unlock(&philo->table->eat);
    //pthread_mutex_unlock(&philo->table->eat);
    better_sleep(philo->table->time_to_eat * 1000);
    if (protected_death(philo))
    {
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        return false;    
    }
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);


    return true;
}

bool philo_sleep(t_philo *philo)
{
    if(protected_death(philo))
        return false;    
    protected_print(philo, "is sleeping");
    better_sleep(philo->table->time_to_sleep * 1000);
    if (protected_death(philo))
        return false;
    return true;
}
bool philo_think (t_philo *philo)
{
    if(protected_death(philo))
        return false;    
    protected_print(philo, "is thinking");
    if (protected_death(philo))
        return false;
    better_sleep(1000);
    return true;
}



