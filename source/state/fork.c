/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:50:03 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 09:49:30 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

int philo_can_use_fork(t_philo *philo, pthread_mutex_t *fork)
{
    if (fork == NULL)
        return (0);
    if (pthread_mutex_lock(fork) == 0)
    {
        printf("[%ld] philo [%d] has taken a fork\n", 
                get_time_pass(philo->times->start_time, get_actual_time()),
                philo->num);
        return (1);
    }
    return (0);
}

int philo_can_use_two_fork(t_philo *philo)
{
    if (pthread_mutex_lock(&philo->fork) == 0
        && pthread_mutex_lock(philo->next_fork) == 0)
    {
        if (there_are_not_dead_philos(philo->env))
        {
            printf("[%ld] philo [%d] has taken two fork\n", 
                get_time_pass(philo->times->start_time, get_actual_time()),
                philo->num);
        }
        return (1);
    }
    return (0);
}

void philo_puts_down_fork(t_philo *philo)
{
    pthread_mutex_unlock(&philo->fork);
    pthread_mutex_unlock(philo->next_fork);
}