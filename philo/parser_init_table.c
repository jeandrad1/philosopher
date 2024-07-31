/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:29:57 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/31 19:14:10 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(const char *str)
{
	int i;
	int res;

	i = 0;
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
        return(ERROR_ARG);
    
    while (i < argc)
    {
		str = argv[i];
		j = 0;
		if (str[0] == '\0')
			return(ERROR_ARG);
        while(str[j])
        {
            if (str[j] < '0' || str[j] > '9' || str[0] == '0')
                return(ERROR_ARG);
            j++;
        }
        i++;
    }
	printf("All arguments are numbers\n");
    return (EXIT_SUCCESS);
}

bool init_table(t_table *table, int argc, char **argv)
{
	printf("Begin inizialization\n");
	table->philo_count = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->eat_count = 0;
	if (argc == 6)
		table->eat_count = ft_atoi(argv[5]);
	table->is_dead = false;
	printf("Table initialized\n");
	return (EXIT_SUCCESS);
}