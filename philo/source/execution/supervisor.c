/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:32:46 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/25 14:56:44 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void	supervisor(t_table *table)
{
	t_philo	*philo;

	philo = get_first_philo(table);
	while (1)
	{
		if (philo_have_no_more_time_to_eat(philo))
		{
			philo_die(philo);
			break ;
		}
		else if (there_are_not_dead_philos(table)
			&& all_philo_have_eat_enough(table))
		{
			if (table->times->number_of_meals != -1)
				printf("Each philo eat [%d] time(s)\n",
					table->times->number_of_meals);
			break ;
		}
		philo = philo->next;
		get_infinite_loop(table, &philo);
	}
	protect_finish_thread(table);
}

void	protect_finish_thread(t_table *table)
{
	t_philo	*philo;

	philo = get_first_philo(table);
	while (philo)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
	}
}

void	get_infinite_loop(t_table *table, t_philo **philo)
{
	if (!(*philo))
		*philo = get_first_philo(table);
}
