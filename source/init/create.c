/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:42:00 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/23 11:41:30 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

void create_supervisor(t_env *env)
{
    t_philo *philo; 

    philo = get_first_philo(env);
    while (1)
    {
        if (philo_have_no_more_time_to_eat(philo))
        {
            philo->env->philo_dead += 1;
            change_state(philo, DEAD);
            print_philo_state(philo);
            printf("nbr meal [%d]\n", philo->nbr_of_meal);
            break;
        }
        philo = philo->next;
        get_infinite_loop(env, &philo);
    }
    finish_thread(env);
    
}

void finish_thread(t_env *env)
{
    t_philo *philo;
    philo = get_first_philo(env);
    while (philo)
    {
        pthread_join(philo->thread, NULL);
        philo = philo->next;
    } 
}

int all_philo_have_not_eat_enough(t_env *env)
{
    t_philo *philo;

    philo = get_first_philo(env);
    while (philo)
    {
        if (philo->nbr_of_meal < philo->times->number_of_meals)
            return (1);
        philo = philo->next;
    }
    return (0);
}

void get_infinite_loop(t_env *env, t_philo **philo)
{
    if (!(*philo))
        *philo = get_first_philo(env);
}

void create_all_threads(t_env *env)
{
	t_philo *philo;

	philo = get_first_philo(env);
	while (philo)
	{
		pthread_create(&philo->thread, NULL, &cycle, philo);
		philo = philo->next;
	}
}

void create_delayed_start(t_philo *philo)
{
   if (philo_is_pair(philo))
    {
        ms_sleep(philo->times->eat_time / 2);
    }
}