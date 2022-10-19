/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:49:09 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/19 17:31:07 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void execution(t_env *env)
{
    t_philo *philo;

    philo = get_first_philo(env);
    while (philo)
    {
        pthread_join(philo->thread, NULL);
        philo = philo->next;
    }
}

void *cycle(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    
    philo_eat(philo);
    if (philo_is_dead(philo))
    {
        
    }
    else
    {
        philo_sleep(philo);
        philo_think(philo);
    }
    return (NULL);
}

void change_state(t_philo *philo, int state)
{
    philo->state = state;
}

int philo_is_dead(t_philo *philo)
{
    if (philo->state == DEAD)
        return (1);
    return (0);
}

void stop_cycle(t_env *env)
{
    
}