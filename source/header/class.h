/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/10 15:54:41 by ebennace         ###   ########.fr       */
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
    int     num;
	int     state;
    float   eat_time;
    float   sleep_time;
    float   die_time;
    int     nbr_of_forks;
    struct s_philo *next;
    struct s_philo *prev;

}   t_philo;


typedef struct s_env
{
    t_philo *first_philo;

}   t_env;

#endif