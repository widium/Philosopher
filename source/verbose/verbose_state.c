/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:58:04 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 15:08:59 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

void print_philo_state(t_philo *philo)
{
    printf("[%ld] philo [%d] [%s]\n",
        get_time_pass(philo->last_eat_time, get_actual_time()),
        philo->num,
        verbose_state(philo->state));
}

char *verbose_state(int state)
{
    if (state == EAT)
        return ("eating"); 
    else if (state == SLEEP)
        return ("sleeping");
    else if (state == THINK)
        return ("thinking");
    else if (state == DEAD)
        return ("dead");
    else if (state == TAKE_FORK)
        return ("has taken fork");
    return (NULL);
}