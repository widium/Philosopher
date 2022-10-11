/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:19:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/11 12:16:50 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void print_philo(t_philo *philo)
{
    if (!philo)
        return ;
    printf("---- Philo Num : [%d] ----\n", philo->num);
    printf("State : [%d]\n", philo->state);
    printf("time to sleep : [%d ms]\n", philo->sleep_time);
    printf("time to eat : [%d ms]\n", philo->eat_time);
    printf("time to die : [%d ms]\n", philo->die_time);
    printf("number of forks : [%d]\n", philo->nbr_of_forks);
    printf("----- ----- -----\n");
}

void print_all_philo(t_env *env)
{
    t_philo *iter;

    if (!env->first_philo)
        return;
    iter = env->first_philo;
    while (iter)
    {
        print_philo(iter);
        iter = iter->next;
    }
}