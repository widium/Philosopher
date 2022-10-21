/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:36:11 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 15:17:39 by ebennace         ###   ########.fr       */
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
    if (have_time_to_eat(philo) && philo_can_eat(philo))
    {  
        change_state(philo, EAT);
        print_philo_state(philo);
        reset_eat_timer(philo);
        add_meal_counter(philo);
        ms_sleep(philo->times->eat_time);
        check_meal_counter(philo);
    }
    else
    {
        philo_die(philo);    
    } 
    philo_puts_down_fork(philo);
}

void check_meal_counter(t_philo *philo)
{
    if (philo->env->count_philo_meal == philo->env->nbr_philo)
            philo->env->count_philo_meal = 0;
}

void add_meal_counter(t_philo *philo)
{
    philo->env->count_philo_meal += 1;
}

void philo_sleep(t_philo *philo)
{
    if (there_are_not_dead_philos(philo->env))
    {
        change_state(philo, SLEEP);
        print_philo_state(philo);
        ms_sleep(philo->times->sleep_time);
        
    }
}

void philo_die(t_philo *philo)
{
    if (there_are_not_dead_philos(philo->env))
    {
        philo->env->philo_dead += 1;
        change_state(philo, DEAD);
        print_philo_state(philo);
    }
    change_state(philo, DEAD);
}

