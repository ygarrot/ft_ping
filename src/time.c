/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:49:30 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/15 15:58:12 by ygarrot          ###   ########.fr       */
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

double timeval_to_double(t_timeval last_time, t_timeval current_time)
{
	double intervale;

	intervale = (double)(current_time.tv_sec - last_time.tv_sec) * 1000.0;
	intervale += (double)(current_time.tv_usec - last_time.tv_usec)
	  / 1000.0 ;
	return (intervale);
}

#define PING_SLEEP_RATE 1000000
double intervale(void)
{
	static t_timeval	last_time = {0.0, 0.0};
	t_timeval			current_time;
	double				intervale;
	/* t_timezone	timezone; */

	/* timezone.tz_dsttime = DST_WEST; */
    /* usleep(PING_SLEEP_RATE); */ 
	if (gettimeofday(&current_time, 0) == ERROR_CODE)
		return (0);
	intervale = timeval_to_double(last_time, current_time);
	last_time = current_time;
	return (intervale);
}

int		set_time_stat(t_ping *ping)
{
	static	double std_sum = 0.0;
	t_time_stat time;

	time = ping->tstat;
	ping->tstat.max = time.intervale > time.max ? time.intervale : time.intervale;
	ping->tstat.min = time.max && (time.intervale > time.min) ? time.min : time.intervale;
	ping->tstat.avg = time.all / time.count;
	std_sum += ft_power(time.intervale - time.avg, 2);
	if (time.count > 0 && std_sum > 0)
		ping->tstat.mdev = ft_sqrt((double)(1.0 / time.count) * std_sum);
	ping->tstat.count++;
	ping->tstat.all += time.intervale;
	return (1);
}
