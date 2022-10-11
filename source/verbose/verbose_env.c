/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:32:41 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/11 11:54:20 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void print_env(t_env *env)
{
	printf("------ Env ------\n");
	printf("number of philo : %d\n", env->nbr_philo);
	printf("die time : %dms\n", env->die_time);
	printf("sleep time : %dms\n", env->sleep_time);
	printf("eat time : %dms\n", env->eat_time);
    if (env->time_must_eat > 0)
	    printf("time must eat : %dms\n", env->time_must_eat);
	printf("----------------\n");
}

void print_error_parsing(void)
{
    printf("------ Error Parsing ------\n");
    printf("the program must take 4 arguments\n");
	printf("number of philo argv[1] -> nbr\n");
	printf("die time argv[2] -> nbr\n");
	printf("sleep time argv[3] -> nbr\n");
	printf("eat time argv[4] -> nbr\n");
	printf("[Optionnal] time must eat argv[5] -> nbr\n");
	printf("----------------\n");
}