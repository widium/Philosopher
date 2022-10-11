/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:56:48 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/11 15:13:02 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>

# include "../libft/libft.h"
# include "class.h"


void parsing(t_env *env, char **argv, int argc);
int check_correct_value(char **argv);
void add_value_to_env(t_env *env, char **argv, int argc);
int env_have_error(t_env *env);

t_philo *init_philo(t_env *env, int num);
t_env *init_env(void);
void generate_philo(t_env *env);

void add_philo_to_list(t_env *env, t_philo *philo);
void connect_philo(t_philo *prev_philo, t_philo *new_philo);

void print_error_parsing(void);
void print_env(t_env *env);
void print_philo(t_philo *philo);
void print_all_philo(t_env *env);



int is_first_philo(t_env *env, t_philo *philo);
int is_last_philo(t_philo *philo);

t_philo *get_first_philo(t_env *env);



void remove_all(t_env *env);
void remove_all_philo(t_env *env);
void remove_philo(t_env *env, t_philo *philo);
void disconnect_philo(t_philo *philo);

#endif