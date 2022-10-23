/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:54:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/23 16:42:47 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

int philo_can_eat(t_philo *philo)
{
    if (there_are_not_dead_philos(philo->env))
        // && have_not_eat_enough(philo))
        return (1);
    return (0);
}

int have_eat_enough(t_philo *philo)
{
    if (philo->nbr_of_meal >= philo->times->number_of_meals)
        return (1);
    return (0);
}

int have_not_eat_enough(t_philo *philo)
{
    if (philo->nbr_of_meal < philo->times->number_of_meals)
        return (1);
    return (0);
}


int philo_can_make_action(t_philo *philo)
{
   if (there_are_not_dead_philos(philo->env))
        return (1);
    return (0); 
}