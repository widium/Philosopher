/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:42:00 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/23 18:09:54 by ebennace         ###   ########.fr       */
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

int all_philo_have_eat_enough(t_env *env)
{
    t_philo *philo;

    philo = get_first_philo(env);
    while (philo)
    {
        if (have_not_eat_enough(philo))
            return (0);
        philo = philo->next;
    }
    return (1);
}

int get_numbers_of_meals_all_philo(t_env *env)
{
    t_philo *philo;

    philo = get_first_philo(env);
    while (philo)
    {
        printf("philo [%d] eat -> [%d]\n", philo->num, philo->nbr_of_meal);
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
   if (philo_is_impair(philo))
    {
        ms_sleep(philo->times->eat_time / 2);
    }
}