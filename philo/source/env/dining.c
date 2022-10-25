/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:54:25 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/24 14:31:46 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void	dining_philosopher(int argc, char **argv)
{
	t_table	*table;

	table = init_env();
	parsing(table, argv, argc);
	if (env_have_error(table))
		print_error_parsing();
	else
	{
		print_env(table);
		generate_philo(table);
		execution(table);
	}
	remove_all(table);
}
