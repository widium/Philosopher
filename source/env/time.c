/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:42:38 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/13 11:45:01 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

unsigned int milli_to_micro(int milliseconde)
{
    unsigned int micro;

    micro = milliseconde * 1000;
    return (micro);
}