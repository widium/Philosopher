/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:05:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/11 15:12:19 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source/header/philosopher.h"

int	main(int argc, char **argv)
{
	// t_philo *philo;
	t_env *env;
	
	env = init_env();
	parsing(env, argv, argc);
	if (env_have_error(env))
		print_error_parsing();
	else
	{
		print_env(env);
		generate_philo(env);
		print_all_philo(env);
	}
	remove_all(env);
	// philo = init_philo(eat_time, sleep_time, die_time);
	// add_philo_to_list(env, philo);
	// print_all_philo(env);
}

void generate_philo(t_env *env)
{
	int index;
	t_philo *philo;

	index = 0;
	while (index < env->nbr_philo)
	{
		philo = init_philo(env, index);
		add_philo_to_list(env, philo);
		index++;
	}
	// print_all_philo(env);
}

// int check_correct_value(char **argv)
// {
// 	int i;
// 	int number;

// 	i = 1;
// 	while (argv[i])
// 	{
// 		number = ft_atoi(argv[i]);
// 		printf("%d\n",number);
// 		i++;
// 	}
// 	return (1);
// }
