/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:27:10 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/15 21:02:26 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/*
** -t
*/

void	set_ttl(t_ping *ping, char *value)
{
	ping->tstat.ttl = ft_atoi(value);
}

/*
** -S
*/

void	set_sndbuff(t_ping *ping, char *value)
{
	ping->pstat.sndbuff = ft_atoi(value);
}

/*
** -s
*/


void	set_packetsize(t_ping *ping, char *value)
{
	ping->pstat.size = ft_atoi(value);
}


/*
** -c
*/

void	set_countmax(t_ping *ping, char *value)
{
	ping->pstat.count_max = ft_atoi(value);
}

/*
** -i
*/

void	set_intervale(t_ping *ping, char *value)
{
	ping->tstat.delay = atof(value);
}


