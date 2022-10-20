/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:36:11 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/20 12:02:44 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void philo_eat(t_philo *philo)
{
    if (there_are_not_dead_philos(philo->env))
    {
        philo->times->last_eat_time = get_actual_time();
        printf("philo [%d] wait\n", philo->num);
        if (philo_can_use_two_fork(philo))
        {
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
                philo->env->count_philo_meal += 1;
                change_state(philo, EAT);
                ms_sleep(philo->times->eat_time);
                // save_last_eat_time(philo);
                philo_puts_down_fork(philo);
            }
        }
    }
    
}
void philo_sleep(t_philo *philo)
{
    if (there_are_not_dead_philos(philo->env))
    {
        printf("philo [%d] sleep...\n", philo->num);
        change_state(philo, SLEEP);
        ms_sleep(philo->times->sleep_time);
    }
}

void philo_think(t_philo *philo)
{
    if (there_are_not_dead_philos(philo->env))
    {
        printf("philo [%d] think...\n", philo->num);
        change_state(philo, THINK);
        ms_sleep(philo->times->die_time);
    }
}

