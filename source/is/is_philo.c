/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:53:22 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/23 18:37:41 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

int philo_is_pair(t_philo *philo)
{
    if (philo->num % 2 == 0)
        return (1);
    return (0);
}

int philo_is_impair(t_philo *philo)
{
    if (philo->num % 2 != 0)
        return (1);
    return (0);
}