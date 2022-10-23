/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:56:48 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/23 16:41:56 by ebennace         ###   ########.fr       */
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

int get_numbers_of_meals_all_philo(t_env *env);
void protect_finish_thread(t_env *env);
void dining_philosopher(int argc, char **argv);
void cycle_for_single_philo(t_philo *philo);
long int    get_actual_time(void);
void *cycle(void *arg);
void execution(t_env *env);
void* routine(void* arg) ;
int	init_threads(int number);
int	sum_array(int size);
void supervisor(t_env *env);
int all_philo_have_not_eat_enough(t_env *env);
void create_delayed_start(t_philo *philo);
void update_meal_counter(t_philo *philo);
int have_error_convertion(int die_t, int sleep_t, int eat_t, int must_eat_t);
void convert_argv_to_millisecond(t_env *env, int argc, char **argv);
void get_infinite_loop(t_env *env, t_philo **philo);

long int get_time_pass(long int start, long int end);
long int milliseconde_to_microseconde(long int milliseconde);
long int microseconde_to_milliseconde(long int micro);
long int seconde_to_milliseconde(long int seconde);
void ms_sleep(long int milliseconde);

int have_not_eat_enough(t_philo *philo);
int have_eat_enough(t_philo *philo);

void parsing(t_env *env, char **argv, int argc);
int check_correct_value(char **argv);
void add_value_to_env(t_env *env, char **argv, int argc);
int env_have_error(t_env *env);
void create_all_threads(t_env *env);
int philo_can_use_fork(t_philo *philo, pthread_mutex_t *fork);
int philo_can_use_two_fork(t_philo *philo);

t_philo *init_philo(t_env *env, int num);
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
void print_philo_state(t_philo *philo);
char *verbose_state(int state);


int philo_is_pair(t_philo *philo);
int philo_is_impair(t_philo *philo);
int is_first_philo(t_env *env, t_philo *philo);
int is_last_philo(t_philo *philo);
int philo_is_dead(t_philo *philo);
int there_are_not_dead_philos(t_env *env);
int there_are_dead_philos(t_env *env);

t_philo *get_first_philo(t_env *env);

void remove_all(t_env *env);
void remove_all_philo(t_env *env);
void remove_philo(t_env *env, t_philo *philo);
void disconnect_philo(t_philo *philo);

void philo_eat(t_philo *philo);
void philo_sleep(t_philo *philo);
void philo_die(t_philo *philo);

int philo_can_eat(t_philo *philo);
int philo_can_make_action(t_philo *philo);
void philo_puts_down_fork(t_philo *philo);
int philo_have_no_more_time_to_eat(t_philo *philo);
int philo_have_time_to_eat(t_philo *philo);

void reset_eat_timer(t_philo *philo);

#endif