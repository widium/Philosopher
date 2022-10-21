/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:50:43 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 17:56:04 by ebennace         ###   ########.fr       */
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

void check_all_philos_meals_counter(t_philo *philo)
{
    if (philo->env->count_all_philos_meals == philo->env->nbr_philo)
            philo->env->count_all_philos_meals = 0;
}

void update_meal_counter(t_philo *philo)
{
    philo->env->count_all_philos_meals += 1;
    philo->nbr_of_meal += 1;
}
