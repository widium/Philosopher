/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:54:25 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 15:54:34 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philosopher.h"

void dining_philosopher(int argc, char **argv)
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
}