/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:34:10 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/24 07:47:08 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void execution(t_env *env)
{
    if (env->nbr_philo == 1)
        cycle_for_single_philo(env->first_philo);
    else 
    {
        create_all_threads(env);
        supervisor(env);
    }
    
}

void *cycle(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    create_delayed_start(philo);
    while (1)
    {   
        if (philo_can_make_action(philo))
        {
            philo_eat(philo);
            philo_sleep(philo);
            philo_think(philo);
        }
        else
            break ;
    }
    return (NULL);
}

void cycle_for_single_philo(t_philo *philo)
{
    change_state(philo, TAKE_FORK);
    print_philo_state(philo);
    ms_sleep(philo->times->die_time);
    change_state(philo, DEAD);
    print_philo_state(philo);
}



