/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:14:03 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/23 17:27:28 by ebennace         ###   ########.fr       */
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
    philo->nbr_of_meal = 0;
    philo->times = env->times;
    philo->next = NULL;
    philo->prev = NULL;
    philo->env = env;
    philo->last_eat_time = philo->times->start_time;
    pthread_mutex_init(&philo->fork, NULL);
    return (philo);
}

t_env *init_env(void)
{
    t_env *env;

    env = (t_env *)malloc(sizeof(t_env));
    if (!env)
        return (NULL);
    env->error_parsing = 0;
    env->nbr_philo = -1;
    env->philo_dead = 0;
    env->times = NULL;
    env->first_philo = NULL;
    return (env);
}

t_times *init_times(int die_t, int eat_t, int sleep_t, int number_meals)
{
    t_times *time;

    time = (t_times *)malloc(sizeof(t_times));
    if (!time)
        return (NULL);
    time->die_time = die_t;
    time->eat_time = eat_t;
    time->sleep_time = sleep_t;
    time->number_of_meals = number_meals;
    return (time);
}


