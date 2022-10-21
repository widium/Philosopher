/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:05:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 14:43:06 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source/header/philosopher.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	env = init_env();
	parsing(env, argv, argc);
	if (env_have_error(env))
		print_error_parsing();
	else
	{
		print_env(env);
		generate_philo(env);
		execution(env);
		
	}
	remove_all(env);
	return (0);
}


