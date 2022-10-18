/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/18 20:22:37 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
# define CLASS_H

# define EAT 0
# define SLEEP 1
# define THINK 2
# define DIE 3

typedef struct s_times
{
    int             die_time;
    int             eat_time;
    int             sleep_time;
    int             time_must_eat; 
}   t_times;

typedef	struct s_philo
{
    int             num;
	int             state;
    pthread_mutex_t fork;
    pthread_mutex_t *next_fork;
    t_times        *times;
    pthread_t       thread;
    struct s_philo  *next;
    struct s_philo  *prev;

}   t_philo;


typedef struct s_env
{
    int             nbr_philo;
    int             error_parsing;
    t_times        *times;
    t_philo         *first_philo;

}   t_env;

#endif