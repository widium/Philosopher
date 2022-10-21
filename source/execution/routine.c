/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:34:10 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 12:19:43 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void execution(t_env *env)
{
    t_philo *philo;

    philo = get_first_philo(env);
    // while (philo)
    // {
    //     // pthread_join(philo->thread, NULL);  
    //     philo = philo->next;
    // }
    // philo = get_first_philo(env);
    while (1)
    {
        // printf("MEAL TIME [%d]\n", get_time_pass(philo->last_eat_time, get_actual_time()) >= philo->times->die_time);
        if (no_more_time_to_eat(philo))
        {
            printf("philo [%d] DEAD [%ld]\n", 
            philo->num, 
            get_time_pass(philo->times->start_time, get_actual_time()));
            break;
        }
        // printf("MEAL TIME [%d]\n", get_time_pass(philo->last_eat_time, get_actual_time()) >= philo->times->die_time);
        philo = philo->next;
        if (!philo)
            philo = get_first_philo(env);
    }
    
}

void *cycle(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    
    // philo->times->start_time = get_actual_time();
    // philo->last_eat_time = philo->times->start_time;
    if (philo_is_pair(philo))
    {
        ms_sleep(philo->times->eat_time/2);
    }
    while (1)
    {   
        if (there_are_dead_philos(philo->env))
            break;
        philo_eat(philo);
        philo_sleep(philo);
    }
    return (NULL);
}

