/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:36:11 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 15:05:41 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void philo_eat(t_philo *philo)
{
    if (philo_can_use_two_fork(philo))
    {
        if (philo_can_eat(philo))
        {
            philo_die_or_eat(philo);
        }   
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
            
            // printf("[%ld] philo [%d] eat timer :[%ld]\n", 
            //     get_time_pass(philo->times->start_time, get_actual_time()),
            //     philo->num);
            change_state(philo, EAT);
            print_philo_state(philo);
            save_last_eat_time(philo);
            philo->env->count_philo_meal += 1;
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
        change_state(philo, SLEEP);
        print_philo_state(philo);
        // printf("[%ld] philo [%d] sleep\n",
        //     get_time_pass(philo->times->start_time, get_actual_time()),
        //     philo->num);
        ms_sleep(philo->times->sleep_time);
        
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
        change_state(philo, DEAD);
        print_philo_state(philo);
        // printf("philo [%d] DEAD [%ld]\n", 
        //     philo->num, 
        //     get_time_pass(philo->times->start_time, get_actual_time()));
    }
    change_state(philo, DEAD);
}

