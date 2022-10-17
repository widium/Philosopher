/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:14:03 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/17 15:01:56 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

t_philo *init_philo(int num)
{
    t_philo *philo;

    philo = (t_philo *)malloc(sizeof(t_philo));
    if (!philo)
        return (NULL);
    philo->num = num;
    philo->state = -1;
    philo->right_fork = -1;
    philo->left_fork = -1;
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

void generate_philo(t_env *env)
{
	int index;
	t_philo *philo;

	index = 0;
	while (index < env->nbr_philo)
	{
		philo = init_philo(index);
		add_philo_to_list(env, philo);
		index++;
	}
}


