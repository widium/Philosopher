/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:58:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/24 07:52:15 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void parsing(t_env *env, char **argv, int argc)
{
	if (argc < 7 && argc > 4)
		add_value_to_env(env, argv, argc);
	else
		env->error_parsing++;
		
}

void add_value_to_env(t_env *env, char **argv, int argc)
{	
	env->nbr_philo = ft_atoi(argv[1]);
	if (env->nbr_philo == 0)
		env->error_parsing++;
	convert_argv_to_millisecond(env, argc, argv);
}

void convert_argv_to_millisecond(t_env *env, int argc, char **argv)
{
	int die_t;
	int sleep_t;
	int eat_t;
	int number_meals;
	
	die_t = ft_atoi(argv[2]);
	sleep_t = ft_atoi(argv[3]);
	eat_t = ft_atoi(argv[4]);
	if (argc == 6)
		number_meals = ft_atoi(argv[5]);
	else
		number_meals = -1;
	if (have_error_convertion(die_t, sleep_t, eat_t, number_meals))
		env->error_parsing++;
	else 
		env->times = init_times(die_t, eat_t, sleep_t, number_meals);
}

int have_error_convertion(int die_t, int sleep_t, int eat_t, int number_meals)
{
	if (die_t <= 0 || sleep_t <= 0
		|| eat_t <= 0 || number_meals <= 0)
		return (1);
	return (0);
}

int env_have_error(t_env *env)
{
	if (env->error_parsing > 0)
		return (1);
	return (0);
}