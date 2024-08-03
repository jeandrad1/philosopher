/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:29:57 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/03 18:27:14 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int ft_atoi(const char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

bool    parse(int argc, char **argv)
{
    int     i;
    int     j;
    char    *str;

    i = 1;
    j = 0;
    if (argc < 5 || argc > 6)
        return(FAILURE);
    
    while (i < argc)
    {
		str = argv[i];
		j = 0;
		if (str[0] == '\0')
			return(FAILURE);
        while(str[j])
        {
            if (str[j] < '0' || str[j] > '9' || str[0] == '0')
                return(FAILURE);
            j++;
        }
        i++;
    }
    return (SUCCESS);
}

static bool	ft_mutex_create(t_table *table)
{
	int i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_count);
	if(!table->forks)
	{
		printf("Error creating forks\n");
		return (FAILURE);
	}
	if(pthread_mutex_init(&table->is_dead,NULL) != 0)
	{
		printf("Error creating dead\n");
		return (FAILURE);
	}
	while (i < table->philo_count)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			printf("Error creating forks\n");
		i++;
	}
	
	if (pthread_mutex_init(&table->print, NULL) != 0)
	{
		printf("Error creating print\n");
		return (FAILURE);
	}
	if (pthread_mutex_init(&table->is_dead, NULL) != 0)
	{
		pthread_mutex_destroy(&table->print);
		printf("Error creating dead\n");
		return (FAILURE);
	}
	if (pthread_mutex_init(&table->eat, NULL) != 0)
	{
			pthread_mutex_destroy(&table->print);
			pthread_mutex_destroy(&table->is_dead);
			printf("Error creating eat\n");
			return (FAILURE);
	}
	if (pthread_mutex_init(&table->ready, NULL) != 0)
	{
		pthread_mutex_destroy(&table->print);
		pthread_mutex_destroy(&table->is_dead);
		pthread_mutex_destroy(&table->eat);
		printf("Error creating ready\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

bool init_table(t_table *table, int argc, char **argv)
{
	table->philo_count = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->eat_max = 0;
	table->dead = false;
	if (argc == 6)
		table->eat_max = ft_atoi(argv[5]);
	if (!ft_mutex_create(table))
		return (FAILURE);
	return (SUCCESS);
}