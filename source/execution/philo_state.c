/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:36:11 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/19 18:21:05 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void philo_eat(t_philo *philo)
{
    philo->times->last_eat_time = get_actual_time();
    printf("philo [%d] wait\n", philo->num);
    if (philo_can_use_two_fork(philo))
    {
        printf("philo [%d] unlock 2 fork\n", philo->num);
        if (no_more_time_to_eat(philo))
        {
            change_state(philo, DEAD);
            philo->env->philo_dead += 1;
            printf("philo [%d] DEAD XX\n", philo->num);
            philo_puts_down_fork(philo);
            return ;
        }
        else
        {
            printf("philo [%d] eat...\n", philo->num);
            change_state(philo, EAT);
            ms_sleep(philo->times->eat_time);
            // save_last_eat_time(philo);
            philo_puts_down_fork(philo);
        }
    }
}

int no_more_time_to_eat(t_philo *philo)
{
    if (get_time_pass(philo->times->last_eat_time, get_actual_time()) >= philo->times->die_time)
        return (1);
    return (0);
}
void philo_sleep(t_philo *philo)
{
    printf("philo [%d] sleep...\n", philo->num);
    change_state(philo, SLEEP);
    ms_sleep(philo->times->sleep_time);
}

void philo_think(t_philo *philo)
{
    printf("philo [%d] think...\n", philo->num);
    change_state(philo, THINK);
    ms_sleep(philo->times->die_time);
}

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

void save_last_eat_time(t_philo *philo)
{
    philo->times->last_eat_time = get_actual_time();
}