/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:36:11 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/23 18:12:05 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void philo_eat(t_philo *philo)
{
    if (philo_can_use_two_fork(philo))
    {
        if (philo_can_make_action(philo))
        {
            change_state(philo, EAT);
            print_philo_state(philo);
            reset_eat_timer(philo);
            update_meal_counter(philo);
            ms_sleep(philo->times->eat_time);
        }
    }
    philo_puts_down_fork(philo);
}


void philo_sleep(t_philo *philo)
{
    if (philo_can_make_action(philo))
    {
        change_state(philo, SLEEP);
        print_philo_state(philo);
        ms_sleep(philo->times->sleep_time);
    }
}



void philo_die(t_philo *philo)
{
    if (philo_can_make_action(philo))
    {
        philo->env->philo_dead += 1;
        change_state(philo, DEAD);
        print_philo_state(philo);
    }
    change_state(philo, DEAD);
}

