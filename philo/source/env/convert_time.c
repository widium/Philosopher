/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:39:45 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/24 11:56:32 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

long int	milliseconde_to_microseconde(long int milliseconde)
{
	long int	micro;

	micro = milliseconde * 1000;
	return (micro);
}

long int	microseconde_to_milliseconde(long int micro)
{
	long int	milli;

	milli = micro / 1000;
	return (milli);
}

long int	seconde_to_milliseconde(long int seconde)
{
	long int	milli;

	milli = seconde * 1000;
	return (milli);
}
