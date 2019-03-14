/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:49:30 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/14 14:07:37 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/*
struct timeval {
    time_t      tv_sec;      seconds 
    suseconds_t tv_usec;     microseconds 
};

struct timezone {
    int tz_minuteswest;      minutes west of Greenwich 
    int tz_dsttime;          type of DST correction 
};
The tz_dsttime field has never been used under Linux. Thus, the following is purely of historic interest.
*/


double intervale(void)
{
	/* t_timezone	timezone; */
	static t_timeval start;
	static t_timeval current_time;

	/* timezone.tz_dsttime = DST_WET; */
	(void)start;
	(void)current_time;
	if (gettimeofday(&current_time, 0) == ERROR_CODE)
		return (0);
	/* last_time = c */
	return 1;
}
