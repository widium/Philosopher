/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:50:43 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 15:52:56 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

int philo_have_no_more_time_to_eat(t_philo *philo)
{
    if (get_time_pass(philo->last_eat_time, get_actual_time())
        >= philo->times->die_time)
        return (1);
    return (0);
}

int philo_have_time_to_eat(t_philo *philo)
{
    if (get_time_pass(
        philo->last_eat_time, get_actual_time()) < philo->times->die_time)
        return (1);
    return (0);
}

void reset_eat_timer(t_philo *philo)
{
    philo->last_eat_time = get_actual_time();
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
