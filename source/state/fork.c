/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:50:03 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/20 11:50:25 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

int philo_can_use_two_fork(t_philo *philo)
{
    if (pthread_mutex_lock(&philo->fork) == 0
        && pthread_mutex_lock(philo->next_fork) == 0)
        return (1);
    return (0);
}

void philo_puts_down_fork(t_philo *philo)
{
    pthread_mutex_unlock(&philo->fork);
    pthread_mutex_unlock(philo->next_fork);
}