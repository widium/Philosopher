/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:50:03 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/23 11:44:26 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

int philo_can_use_fork(t_philo *philo, pthread_mutex_t *fork)
{
    if (fork == NULL)
        return (0);
    if (pthread_mutex_lock(fork) == 0)
    {
        if (there_are_not_dead_philos(philo->env))
        {
            change_state(philo, TAKE_FORK);
            print_philo_state(philo);
        }
        return (1);
    }
    return (0);
}

int philo_can_use_two_fork(t_philo *philo)
{
    if (philo_can_use_fork(philo, &philo->fork)
        && philo_can_use_fork(philo, philo->next_fork))
        return (1);
    return (0);
}

void philo_puts_down_fork(t_philo *philo)
{
    pthread_mutex_unlock(&philo->fork);
    pthread_mutex_unlock(philo->next_fork);
}