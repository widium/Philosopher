/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:58:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/18 18:38:23 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void parsing(t_env *env, char **argv, int argc)
{
	if (argc < 7 && argc > 4)
		add_value_to_env(env, argv, argc);
	else
		env->error_parsing = 1;
}

void add_value_to_env(t_env *env, char **argv, int argc)
{
	int die_t;
	int sleep_t;
	int eat_t;
	int must_eat_t;
	
	env->nbr_philo = ft_atoi(argv[1]);
	die_t = ft_atoi(argv[2]);
	sleep_t = ft_atoi(argv[3]);
	eat_t = ft_atoi(argv[4]);
	if (argc == 6)
		must_eat_t = ft_atoi(argv[5]);
	else
		must_eat_t = -1;
	env->times = init_times(die_t, eat_t, sleep_t, must_eat_t);
	
}

int env_have_error(t_env *env)
{
	if (env->error_parsing > 0)
		return (1);
	return (0);
}