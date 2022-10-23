/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:50:43 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/23 19:28:14 by ebennace         ###   ########.fr       */
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


void reset_eat_timer(t_philo *philo)
{
    philo->last_eat_time = get_actual_time();
}

// void check_philo_meal_counter(t_philo *philo)
// {
//     if (philo->nbr_of_meal == philo->times->number_of_meals)
//         philo->nbr_of_meal = 0;
// }

void update_meal_counter(t_philo *philo)
{
    philo->nbr_of_meal += 1;
}
