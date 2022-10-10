/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:05:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/10 16:11:21 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source/header/philosopher.h"

int	main(void)
{
	float eat_time = 0.50;
	float sleep_time = 0.70;
	float die_time = 2.0; 
	t_philo *philo;
	t_env *env;

	env = init_env();
	philo = init_philo(eat_time, sleep_time, die_time);
	add_philo_to_list(env, philo);
	print_philo(env->first_philo);
}
