/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:50:43 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/11 14:57:30 by ebennace         ###   ########.fr       */
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