/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:19:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/07 18:35:21 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void print_philo(t_philo *philo)
{
    if (!philo)
        return ;
    printf("---- Philo Num : [%d] ----\n", philo->num);
    printf("State : [%d]\n", philo->state);
    printf("time to sleep : [%f]\n", philo->sleep_time);
    printf("time to eat : [%f]\n", philo->eat_time);
    printf("time to die : [%f]\n", philo->die_time);
    printf("number of forks : [%d]\n", philo->nbr_of_forks);
    printf("----- ----- -----\n");
}