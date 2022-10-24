/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:32:46 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/24 07:48:54 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

void supervisor(t_env *env)
{
    t_philo *philo; 

    philo = get_first_philo(env);
    while (1)
    {
        if (philo_have_no_more_time_to_eat(philo) && have_not_eat_enough(philo))
        {
            philo_die(philo);
            break;
        }
        else if (there_are_not_dead_philos(env) && all_philo_have_eat_enough(env))
        {
            if (env->times->number_of_meals != -1)
                printf("Each philo eat [%d] time(s)\n", env->times->number_of_meals);
            break;
        }
        philo = philo->next;
        get_infinite_loop(env, &philo);
    }
    protect_finish_thread(env);
    
}

void protect_finish_thread(t_env *env)
{
    t_philo *philo;
    philo = get_first_philo(env);
    while (philo)
    {
        pthread_join(philo->thread, NULL);
        philo = philo->next;
    } 
}

void get_infinite_loop(t_env *env, t_philo **philo)
{
    if (!(*philo))
        *philo = get_first_philo(env);
}