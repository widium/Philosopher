/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:54:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/25 14:54:38 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

int	philo_can_make_action(t_philo *philo)
{
	if (there_are_not_dead_philos(philo->table)
		&& !all_philo_have_eat_enough(philo->table))
		return (1);
	return (0);
}

int	there_are_not_dead_philos(t_table *table)
{
	if (table->philo_dead == 0)
		return (1);
	return (0);
}

int	have_not_eat_enough(t_philo *philo)
{
	if (philo->times->number_of_meals == -1)
		return (1);
	if (philo->nbr_of_meal < philo->times->number_of_meals)
		return (1);
	return (0);
}
