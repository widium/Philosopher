/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:50:43 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/23 17:55:39 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

int is_first_philo(t_env *env, t_philo *philo)
{
    if (env->first_philo == philo)
        return (1);
    return (0);
}

int is_last_philo(t_philo *philo)
{
    if (philo->next)
        return (0);
    return (1);
}

int there_are_dead_philos(t_env *env)
{
    if (env->philo_dead > 0)
        return (1);
    return (0);
} 

int there_are_not_dead_philos(t_env *env)
{
    if (env->philo_dead == 0)
        return (1);
    return (0);
} 