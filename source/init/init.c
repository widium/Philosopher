/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:14:03 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/10 16:00:49 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

t_philo *init_philo(float eat_time, float sleep_time, float die_time)
{
    t_philo *philo;

    philo = (t_philo *)malloc(sizeof(t_philo));
    if (!philo)
        return (NULL);
    philo->num = -1;
    philo->state = -1;
    philo->nbr_of_forks = -1;
    philo->eat_time = eat_time;
    philo->sleep_time = sleep_time;
    philo->die_time = die_time;
    philo->next = NULL;
    philo->prev = NULL;
    return (philo);
}

t_env *init_env(void)
{
    t_env *env;

    env = (t_env *)malloc(sizeof(t_env));
    if (!env)
        return (NULL);
    env->first_philo = NULL;
    return (env);
}

