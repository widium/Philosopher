/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:58:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/11 11:59:48 by ebennace         ###   ########.fr       */
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
		env->nbr_philo = ft_atoi(argv[1]);
		env->die_time = ft_atoi(argv[2]);
		env->sleep_time = ft_atoi(argv[3]);
		env->eat_time = ft_atoi(argv[4]);
	if (argc == 6)
		env->time_must_eat = ft_atoi(argv[5]);
}

int env_have_error(t_env *env)
{
	if (env->error_parsing > 0)
		return (1);
	return (0);
}