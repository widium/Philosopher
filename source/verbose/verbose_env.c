/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:32:41 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 18:05:01 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void print_env(t_env *env)
{
	printf("------ Env ------\n");
	printf("number of philo : %d\n", env->nbr_philo);
	printf("die time : %dms\n", env->times->die_time);
	printf("sleep time : %dms\n", env->times->sleep_time);
	printf("eat time : %dms\n", env->times->eat_time);
    if (env->times->number_of_meals > 0)
	    printf("number of meals : %d\n", env->times->number_of_meals);
	printf("----------------\n");
}

void print_error_parsing(void)
{
    printf("------ Error Parsing ------\n");
    printf("the program must take 4 number arguments\n");
	printf("--\n");
	printf("number of philo argv[1] : int\n");
	printf("--\n");
	printf("die time argv[2] : int\n");
	printf("--\n");
	printf("sleep time argv[3] : int\n");
	printf("--\n");
	printf("eat time argv[4] : int\n");
	printf("--\n");
	printf("[Optionnal] number of meals argv[5] : int\n");
	printf("----------------\n");
}