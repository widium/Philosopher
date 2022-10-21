/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:54:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 08:55:07 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

int all_philo_have_eat(t_philo *philo)
{
    if (philo->env->count_philo_meal == philo->env->nbr_philo)
        return (1);
    return (0);
}

int all_philo_didnt_eat(t_philo *philo)
{
    if (philo->env->count_philo_meal < philo->env->nbr_philo)
        return (1);
    return (0);
}

int philo_can_eat(t_philo *philo)
{
    if (there_are_not_dead_philos(philo->env) && all_philo_didnt_eat(philo))
        return (1);
    return (0);
}

int philo_can_make_action(t_philo *philo)
{
   if (there_are_not_dead_philos(philo->env))
        return (1);
    return (0); 
}