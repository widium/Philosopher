/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:49:09 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/18 19:56:36 by ebennace         ###   ########.fr       */
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
    printf("philo eat...\n");
    ms_sleep(philo->times->eat_time);
    printf("philo sleep...\n");
    ms_sleep(philo->times->sleep_time);
    return (NULL);
}