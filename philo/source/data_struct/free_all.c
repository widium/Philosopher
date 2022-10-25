/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:39:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/24 14:31:46 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void	remove_all(t_table *table)
{
	remove_all_philo(table);
	free(table->times);
	free(table);
}

void	remove_all_philo(t_table *table)
{
	t_philo	*iter;
	t_philo	*philo;

	if (!(table->first_philo))
		return ;
	philo = get_first_philo(table);
	while (philo)
	{
		iter = philo->next;
		remove_philo(table, philo);
		philo = iter;
	}
}

void	remove_philo(t_table *table, t_philo *philo)
{
	if (is_first_philo(table, philo))
	{
		if (is_last_philo(philo))
			table->first_philo = NULL;
		else
			table->first_philo = philo->next;
	}
	disconnect_philo(philo);
	philo->times = NULL;
	free(philo);
	philo = NULL;
}

void	disconnect_philo(t_philo *philo)
{
	t_philo	*prev;
	t_philo	*next;

	prev = philo->prev;
	next = philo->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	philo->next = NULL;
	philo->prev = NULL;
}
