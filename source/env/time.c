/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_ms.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:42:38 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/18 14:37:56 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

long int    get_actual_time(void)
{
    long int        time_ms;
    long int        seconde;
    long int        microseconde;
    struct timeval  current_time;
    
    gettimeofday(&current_time, NULL);
    seconde = seconde_to_milliseconde(current_time.tv_sec);
    microseconde = microseconde_to_milliseconde(current_time.tv_usec);
    time_ms = seconde + microseconde;
    return (time_ms);
}

long int milliseconde_to_microseconde(long int milliseconde)
{
    long int micro;

    micro = milliseconde * 1000;
    return (micro);
}

long int microseconde_to_milliseconde(long int micro)
{
    long int milli;

    milli = micro / 1000;
    return (milli);
}

long int seconde_to_milliseconde(long int seconde)
{
    long int milli;

    milli = seconde * 1000;
    return (milli);
}

void ms_sleep(long int milliseconde)
{
    long int	start_time;
    long int    timer_ms;

	start_time = get_actual_time();
    timer_ms = get_time_pass(start_time, get_actual_time());
	while (timer_ms < milliseconde)
    {
        timer_ms = get_time_pass(start_time, get_actual_time());
        usleep(milliseconde / 10);
    }
		
}

long int get_time_pass(long int start, long int end)
{
    return (end - start);
}
