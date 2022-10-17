/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:19:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/17 14:50:55 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void print_philo(t_philo *philo)
{
    if (!philo)
        return ;
    printf("---- Philo Num : [%d] ----\n", philo->num);
    printf("State : [%d]\n", philo->state);
    printf("right forks : [%d]\n", philo->right_fork);
    printf("left forks : [%d]\n", philo->left_fork);
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