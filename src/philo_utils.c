/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:33:32 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/09 16:24:45 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		memset(ptr, 0, total_size);
	}
	return (ptr);
}

// This function converts a string to an integer 
// Only allows positive numbers                  
int	ft_atoi(const char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int		r;
	int		i;

	r = 0;
	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
		{
			r = (unsigned char) str1[i] - (unsigned char) str2[i];
			return (r);
		}
		i++;
	}
	return (r);
}
