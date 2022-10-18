/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:14:03 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/18 20:23:31 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

t_philo *init_philo(t_times *times, int num)
{
    t_philo *philo;

    philo = (t_philo *)malloc(sizeof(t_philo));
    if (!philo)
        return (NULL);
    philo->num = num;
    philo->state = -1;
    philo->times = times;
    philo->next = NULL;
    philo->prev = NULL;
    pthread_mutex_init(&philo->fork, NULL);
    return (philo);
}

t_env *init_env(void)
{
    t_env *env;

    env = (t_env *)malloc(sizeof(t_env));
    if (!env)
        return (NULL);
    env->error_parsing = -1;
    env->nbr_philo = -1;
    env->times = NULL;
    env->first_philo = NULL;
    return (env);
}

t_times *init_times(int die_t, int eat_t, int sleep_t, int must_eat_t)
{
    t_times *time;

    time = (t_times *)malloc(sizeof(t_times));
    if (!time)
        return (NULL);
    time->die_time = die_t;
    time->eat_time = eat_t;
    time->sleep_time = sleep_t;
    time->time_must_eat = must_eat_t;
    return (time);
}

void generate_philo(t_env *env)
{
	int index;
	t_philo *philo;

	index = 0;
	while (index < env->nbr_philo)
	{
		philo = init_philo(env->times, index);
        pthread_create(&philo->thread, NULL, &cycle, philo);
		add_philo_to_list(env, philo);
		index++;
	}
    give_fork_at_philo(env);
    
}

void give_fork_at_philo(t_env *env)
{
    t_philo *philo;
    t_philo *first_philo;

    philo = get_first_philo(env);
    while (philo->next)
    {
        philo->next_fork = &philo->next->fork;
        philo = philo->next;
    }
    first_philo = get_first_philo(env);
    philo->next_fork = &first_philo->fork;
}


