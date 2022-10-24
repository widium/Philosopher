/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:42:00 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/23 18:34:59 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

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