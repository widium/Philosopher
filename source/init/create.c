/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:42:00 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/23 15:12:41 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

void supervisor(t_env *env)
{
    t_philo *philo; 

    philo = get_first_philo(env);
    while (1)
    {
        if (philo_have_no_more_time_to_eat(philo))
        {
            philo_die(philo);
            printf("nbr meal [%d]\n", philo->nbr_of_meal);
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