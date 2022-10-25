/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:56:48 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/24 14:31:46 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>

# include "class.h"

void		dining_philosopher(int argc, char **argv);

t_philo		*init_philo(t_table *table, int num);
t_table		*init_env(void);
t_times		*init_times(int die_t, int eat_t, int sleep_t, int number_meals);
void		generate_philo(t_table *table);
void		add_philo_to_list(t_table *table, t_philo *philo);
void		connect_philo(t_philo *prev_philo, t_philo *new_philo);

void		cycle_for_single_philo(t_philo *philo);
void		*cycle(void *arg);

void		execution(t_table *table);

void		supervisor(t_table *table);
void		protect_finish_thread(t_table *table);

void		create_delayed_start(t_philo *philo);
void		create_all_threads(t_table *table);

int			philo_can_make_action(t_philo *philo);
int			philo_have_no_more_time_to_eat(t_philo *philo);

int			philo_is_pair(t_philo *philo);
int			philo_is_impair(t_philo *philo);
int			is_first_philo(t_table *table, t_philo *philo);
int			is_last_philo(t_philo *philo);

int			have_error_convertion(int die_t, int sleep_t, int eat_t,
				int nbr_meals);
int			have_not_eat_enough(t_philo *philo);
int			all_philo_have_eat_enough(t_table *table);
int			there_are_not_dead_philos(t_table *table);

t_philo		*get_first_philo(t_table *table);
void		get_infinite_loop(t_table *table, t_philo **philo);

long int	get_actual_time(void);
long int	get_time_pass(long int start, long int end);
long int	milliseconde_to_microseconde(long int milliseconde);
long int	microseconde_to_milliseconde(long int micro);
long int	seconde_to_milliseconde(long int seconde);
void		ms_sleep(long int milliseconde);

void		reset_eat_timer(t_philo *philo);
void		update_meal_counter(t_philo *philo);
void		convert_argv_to_millisecond(t_table *table, int argc, char **argv);

void		parsing(t_table *table, char **argv, int argc);
int			check_correct_value(char **argv);
void		add_value_to_env(t_table *table, char **argv, int argc);
int			env_have_error(t_table *table);

void		change_state(t_philo *philo, int state);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_die(t_philo *philo);
void		philo_think(t_philo *philo);

int			philo_can_use_fork(t_philo *philo, pthread_mutex_t *fork);
int			philo_can_use_two_fork(t_philo *philo);
void		give_fork_at_philo(t_table *table);
void		philo_puts_down_fork(t_philo *philo);

void		print_error_parsing(void);
void		print_env(t_table *table);
void		print_philo(t_philo *philo);
void		print_all_philo(t_table *table);
void		print_philo_state(t_philo *philo);
char		*verbose_state(int state);

void		remove_all(t_table *table);
void		remove_all_philo(t_table *table);
void		remove_philo(t_table *table, t_philo *philo);
void		disconnect_philo(t_philo *philo);

int			ft_atoi(const char *str);

#endif