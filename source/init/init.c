/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:14:03 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/11 12:15:20 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

t_philo *init_philo(t_env *env, int num)
{
    t_philo *philo;

    philo = (t_philo *)malloc(sizeof(t_philo));
    if (!philo)
        return (NULL);
    philo->num = num;
    philo->state = -1;
    philo->nbr_of_forks = -1;
    philo->eat_time = env->eat_time;
    philo->sleep_time = env->sleep_time;
    philo->die_time = env->die_time;
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
    env->die_time = -1;
    env->eat_time = -1;
    env->error_parsing = -1;
    env->nbr_philo = -1;
    env->sleep_time = -1;
    env->time_must_eat = -1;
    env->first_philo = NULL;
    return (env);
}

