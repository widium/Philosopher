/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:52:55 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/24 14:31:46 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void	add_philo_to_list(t_table *table, t_philo *philo)
{
	t_philo	*iter;

	if (!table->first_philo)
		table->first_philo = philo;
	else
	{
		iter = table->first_philo;
		while (iter->next)
		{
			iter = iter->next;
		}
		connect_philo(iter, philo);
	}
}

void	connect_philo(t_philo *prev_philo, t_philo *new_philo)
{
	new_philo->prev = prev_philo;
	prev_philo->next = new_philo;
}
