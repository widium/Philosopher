/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:09:21 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 12:27:03 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

void generate_philo(t_env *env)
{
	int index;
	t_philo *philo;

	index = 1;
    env->times->start_time = get_actual_time();
	while (index <= env->nbr_philo)
	{
		philo = init_philo(env, index);
		add_philo_to_list(env, philo);
		index++;
	}
    give_fork_at_philo(env);
    
}

void give_fork_at_philo(t_env *env)
{
    t_philo *philo;
    t_philo *first_philo;

    philo = get_first_philo(env);
    while (philo->next)
    {
        philo->next_fork = &philo->next->fork;
        philo = philo->next;
    }
    if (env->nbr_philo > 1)
    {
        first_philo = get_first_philo(env);
        philo->next_fork = &first_philo->fork;
    }
    else 
    {
        philo->next_fork = NULL;
    }
}