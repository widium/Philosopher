/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:50:43 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/23 18:36:02 by ebennace         ###   ########.fr       */
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

int all_philo_have_eat_enough(t_env *env)
{
    t_philo *philo;

    philo = get_first_philo(env);
    while (philo)
    {
        if (have_not_eat_enough(philo))
            return (0);
        philo = philo->next;
    }
    return (1);
}

