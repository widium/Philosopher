/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:52:31 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/20 11:53:07 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

void change_state(t_philo *philo, int state)
{
    philo->state = state;
}

int philo_is_dead(t_philo *philo)
{
    if (philo->state == DEAD)
        return (1);
    return (0);
}