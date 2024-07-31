/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:29:57 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/31 16:50:11 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    parse(int argc, char **argv)
{
    int     i;
    int     j;
    char    *str;

    i = 1;
    j = 0;
    if (argc < 5 || argc > 6)
        error_exit("Error: Invalid number of arguments");
    
    while (i < argc)
    {
		str = argv[i];
		j = 0;
		if (str[0] == '\0')
			error_exit("Error: Arguments must be integers");
        while(str[j])
        {
            if (str[j] < '0' || str[j] > '9' || str[0] == '0')
                error_exit("Error: Arguments must be integers");
            j++;
        }
        i++;
    }
    
}