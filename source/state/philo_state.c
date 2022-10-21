/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:36:11 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 12:33:25 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void philo_eat(t_philo *philo)
{
    if (philo_can_use_fork(philo, &philo->fork)
        && philo_can_use_fork(philo, philo->next_fork))
    {
        if (philo_can_eat(philo))
            philo_die_or_eat(philo);
    }
}

void philo_die_or_eat(t_philo *philo)
{
    if (no_more_time_to_eat(philo))
    {
        philo_die(philo);
    }
    else
    {
        if (philo_can_eat(philo))
        {
            printf("[%ld] philo [%d] eat timer :[%ld]\n", 
                get_time_pass(philo->times->start_time, get_actual_time()),
                philo->num,
                get_time_pass(philo->last_eat_time , get_actual_time()));
            save_last_eat_time(philo);
            philo->env->count_philo_meal += 1;
            change_state(philo, EAT);
            ms_sleep(philo->times->eat_time);
            check_meal_counter(philo);
        }
    } 
    philo_puts_down_fork(philo);
}

void check_meal_counter(t_philo *philo)
{
    if (philo->env->count_philo_meal == philo->env->nbr_philo)
            philo->env->count_philo_meal = 0;
}

void philo_sleep(t_philo *philo)
{
    if (there_are_not_dead_philos(philo->env))
    {
        printf("[%ld] philo [%d] sleep\n",
            get_time_pass(philo->times->start_time, get_actual_time()),
            philo->num);
        ms_sleep(philo->times->sleep_time);
        change_state(philo, SLEEP);
    }
}

void philo_think(t_philo *philo)
{
    if (there_are_not_dead_philos(philo->env))
    {
        printf("philo [%d] think... [%ld]\n", philo->num, get_time_pass(philo->times->start_time, get_actual_time()));
        change_state(philo, THINK);
        ms_sleep(philo->times->die_time);
    }
}

void philo_die(t_philo *philo)
{
    if (there_are_not_dead_philos(philo->env))
    {
        philo->env->philo_dead += 1;
        printf("philo [%d] DEAD [%ld]\n", 
            philo->num, 
            get_time_pass(philo->times->start_time, get_actual_time()));
    }
    change_state(philo, DEAD);
}

