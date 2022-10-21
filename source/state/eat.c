/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:50:43 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 15:15:05 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

int no_more_time_to_eat(t_philo *philo)
{
    if (get_time_pass(philo->last_eat_time, get_actual_time())
        >= philo->times->die_time)
        return (1);
    return (0);
}

int have_time_to_eat(t_philo *philo)
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