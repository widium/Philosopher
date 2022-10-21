/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:42:00 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 16:40:01 by ebennace         ###   ########.fr       */
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
            change_state(philo, DEAD);
            print_philo_state(philo);
            break;
        }
        philo = philo->next;
        get_infinite_loop(env, &philo);
    }
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