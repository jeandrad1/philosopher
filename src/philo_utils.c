/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:33:32 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/07 10:23:16 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *) str;
	while (n > 0)
	{
		*s = (unsigned char) c;
		s++;
		n--;
	}
	return (str);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = num * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	if (ptr != NULL)
	{
		ft_memset(ptr, 0, total_size);
	}
	return (ptr);
}

// This function converts a string to an integer 
// Only allows positive numbers                  
int ft_atoi(const char *str)
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
