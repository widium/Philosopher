/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:19:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/24 14:31:46 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void	print_philo(t_philo *philo)
{
	if (!philo)
		return ;
	printf("---- Philo Num : [%d] ----\n", philo->num);
	printf("Fork [%p]\n", &philo->fork);
	printf("next_Fork [%p]\n", philo->next_fork);
	printf("----- ----- -----\n");
}

void	print_all_philo(t_table *table)
{
	t_philo	*iter;

	if (!table->first_philo)
		return ;
	iter = table->first_philo;
	while (iter)
	{
		print_philo(iter);
		iter = iter->next;
	}
}
