/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:34:10 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 15:39:09 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void *cycle(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    create_delayed_start(philo);
    while (1)
    {   
        if (there_are_dead_philos(philo->env))
            break;
        philo_eat_or_die(philo);
        philo_sleep(philo);
    }
    return (NULL);
}

void create_delayed_start(t_philo *philo)
{
   if (philo_is_pair(philo))
    {
        ms_sleep(philo->times->eat_time / 2);
    }
}

