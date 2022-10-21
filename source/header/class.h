/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/21 18:05:01 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
# define CLASS_H

# define EAT 0
# define SLEEP 1
# define THINK 2
# define DEAD 3
# define TAKE_FORK 4

typedef struct s_times
{
    int             die_time;
    int             eat_time;
    int             sleep_time;
    int             number_of_meals; 
    long int        start_time;         
}   t_times;

typedef	struct s_philo
{
    int             num;
	int             state;
    int             nbr_of_meal;
    long int        last_eat_time;
    pthread_mutex_t fork;
    pthread_mutex_t *next_fork;
    t_times        *times;
    pthread_t       thread;
    struct s_philo  *next;
    struct s_philo  *prev;
    struct s_env    *env;

}   t_philo;

typedef struct s_env
{
    int             philo_dead;
    int             count_all_philos_meals;
    int             nbr_philo;
    int             error_parsing;
    t_times        *times;
    t_philo         *first_philo;

}   t_env;


#endif