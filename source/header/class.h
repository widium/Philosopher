/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/17 15:03:03 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
# define CLASS_H

# define EAT 0
# define SLEEP 1
# define THINK 2
# define DIE 3

typedef	struct s_philo
{
    int             num;
	int             state;
    int             right_fork;
    int             left_fork;
    pthread_t       thread;
    struct s_philo  *next;
    struct s_philo  *prev;

}   t_philo;


typedef struct s_env
{
    int             nbr_philo;
    int             die_time;
    int             eat_time;
    int             sleep_time;
    int             time_must_eat;
    int             error_parsing;
    pthread_mutex_t mutex;
    t_philo         *first_philo;

}   t_env;

#endif