/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:29:57 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/31 15:36:41 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int check_void(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
        return (1);
    while(str[i])
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || 
            str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
            return (EXIT_SUCCESS);
        i++;
    }
    return (EXIT_FAILURE);
    
}

void    parse(int argc, char **argv)
{
    if (argc < 5 || argc > 6)
        error_exit("Error: Invalid number of arguments");
    
    if (check_void(argv[1]) || check_void(argv[2]) || check_void(argv[3]) || check_void(argv[4]))
        error_exit("Error: Invalid arguments");
    
}