/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:39:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/23 18:41:39 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void remove_all(t_env *env)
{
    remove_all_philo(env);
    free(env->times);
    free(env);
}

void remove_all_philo(t_env *env)
{
    t_philo *iter;
    t_philo *philo;

    if (!(env->first_philo))
        return ;
    philo = get_first_philo(env);
    while (philo)
    {
        iter = philo->next;
        remove_philo(env, philo);
        philo = iter;
    }
}

void remove_philo(t_env *env, t_philo *philo)
{
    if (is_first_philo(env, philo))
    {
        if (is_last_philo(philo))
            env->first_philo = NULL;
        else
            env->first_philo = philo->next;
    }
    disconnect_philo(philo); 
    philo->times = NULL;
    free(philo);
    philo = NULL;    
}

void disconnect_philo(t_philo *philo)
{
    t_philo *prev;
    t_philo *next;
    
    prev = philo->prev;
    next = philo->next;
    if (prev)
        prev->next = next;
    if (next)
       next->prev = prev;
    philo->next = NULL;
    philo->prev = NULL;
}