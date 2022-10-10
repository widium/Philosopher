/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:56:48 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/10 16:10:35 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>

# include "../libft/libft.h"
# include "class.h"

t_philo *init_philo(float eat_time, float sleep_time, float die_time);
t_env *init_env(void);


void add_philo_to_list(t_env *env, t_philo *philo);
void connect_philo(t_philo *prev_philo, t_philo *curr_philo);

void print_philo(t_philo *philo);

#endif