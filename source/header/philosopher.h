/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:56:48 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/19 15:18:44 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>

# include "../libft/libft.h"
# include "class.h"

long int    get_actual_time(void);
void *cycle(void *arg);
void execution(t_env *env);
void* routine(void* arg) ;
int	init_threads(int number);
int	sum_array(int size);

long int get_time_pass(long int start, long int end);
long int get_time_passed(long int start, long int end);
long int milliseconde_to_microseconde(long int milliseconde);
long int microseconde_to_milliseconde(long int micro);
long int seconde_to_milliseconde(long int seconde);
void ms_sleep(long int milliseconde);
void	ft_usleep(long int time_in_ms);

void parsing(t_env *env, char **argv, int argc);
int check_correct_value(char **argv);
void add_value_to_env(t_env *env, char **argv, int argc);
int env_have_error(t_env *env);

t_philo *init_philo(t_times *times, int num);
t_env *init_env(void);
t_times *init_times(int die_t, int eat_t, int sleep_t, int must_eat_t);
void give_fork_at_philo(t_env *env);
void generate_philo(t_env *env);
void change_state(t_philo *philo, int state);

void add_philo_to_list(t_env *env, t_philo *philo);
void connect_philo(t_philo *prev_philo, t_philo *new_philo);

void print_error_parsing(void);
void print_env(t_env *env);
void print_philo(t_philo *philo);
void print_all_philo(t_env *env);
char *verbose_state(int state);



int is_first_philo(t_env *env, t_philo *philo);
int is_last_philo(t_philo *philo);

t_philo *get_first_philo(t_env *env);

void remove_all(t_env *env);
void remove_all_philo(t_env *env);
void remove_philo(t_env *env, t_philo *philo);
void disconnect_philo(t_philo *philo);

void philo_eat(t_philo *philo);
void philo_sleep(t_philo *philo);
void philo_think(t_philo *philo);

int philo_can_use_two_fork(t_philo *philo);
void philo_puts_down_fork(t_philo *philo);
int no_more_time_to_eat(t_philo *philo);

void save_last_eat_time(t_philo *philo);

#endif