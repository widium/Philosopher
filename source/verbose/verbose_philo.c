/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:19:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/19 09:43:43 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void print_philo(t_philo *philo)
{
    if (!philo)
        return ;
    printf("---- Philo Num : [%d] ----\n", philo->num);
    // printf("Fork [%p]\n", &philo->fork);
    // printf("Next Fork [%p]\n", philo->next_fork);
    printf("State : [%s]\n", verbose_state(philo->state));
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

char *verbose_state(int state)
{
    if (state == EAT)
        return ("EAT"); 
    else if (state == SLEEP)
        return ("SLEEP");
    else if (state == THINK)
        return ("THINK");
    else if (state == DEAD)
        return ("DEAD");
    return (NULL);
}