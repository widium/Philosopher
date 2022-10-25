/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:09:21 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/24 14:31:46 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void	generate_philo(t_table *table)
{
	int		index;
	t_philo	*philo;

	index = 1;
	table->times->start_time = get_actual_time();
	while (index <= table->nbr_philo)
	{
		philo = init_philo(table, index);
		add_philo_to_list(table, philo);
		index++;
	}
	give_fork_at_philo(table);
}

void	give_fork_at_philo(t_table *table)
{
	t_philo	*philo;
	t_philo	*first_philo;

	philo = get_first_philo(table);
	while (philo->next)
	{
		philo->next_fork = &philo->next->fork;
		philo = philo->next;
	}
	if (table->nbr_philo > 1)
	{
		first_philo = get_first_philo(table);
		philo->next_fork = &first_philo->fork;
	}
	else
		philo->next_fork = NULL;
}
