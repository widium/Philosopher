/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:49:09 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/19 15:02:26 by ebennace         ###   ########.fr       */
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
    philo_sleep(philo);
    philo_think(philo);
    return (NULL);
}

void change_state(t_philo *philo, int state)
{
    philo->state = state;
}