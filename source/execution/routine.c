/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:34:10 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/20 12:21:44 by ebennace         ###   ########.fr       */
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
    while (there_are_not_dead_philos(philo->env))
    {   
        if (philo_is_pair(philo))
        {
            philo_sleep(philo);
        }
        philo_eat(philo);
        philo_think(philo);
        // printf("all philo eat ? [%d]\n", all_philo_have_eat(philo)); 
    }
    return (NULL);
}

int all_philo_have_eat(t_philo *philo)
{
    if (philo->env->count_philo_meal == philo->env->nbr_philo)
        return (1);
    return (0);
}