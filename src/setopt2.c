/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setopt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:45:19 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/15 18:57:36 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ping.h"

/*
** -w
*/

void	set_deadline(t_ping *ping, char *value)
{
	ping->tstat.deadline = ft_atoi(value);
}

/*
** -W
*/

void	set_timeout(t_ping *ping, char *value)
{
	ping->tstat.timeout = ft_atoi(value);
}

void	display_help(t_ping *ping, char *value)
{
	(void)ping;
	(void)value;
	printf("%s\n", OPT_STR);
}

void	func_tab(t_ping *ping)
{
	int i;
	int	index;
	void	(*f[16])(t_ping *p, char *);

	f[ft_strlento(OPT_STR,'t')] = set_ttl;
	f[ft_strlento(OPT_STR,'s')] =  set_sndbuff;
	/* f[ft_strlento(OPT_STR,'p')] = set_packetsize; */
	f[ft_strlento(OPT_STR,'c')] = set_countmax;
	f[ft_strlento(OPT_STR,'w')] = set_deadline;
	f[ft_strlento(OPT_STR,'W')] = set_timeout;
	f[ft_strlento(OPT_STR,'h')] = display_help;
	f[ft_strlento(OPT_STR,'i')] = set_intervale;
	i = 0;
	index = 0;
	while (index < 64)
	{
		index++;
		if (ping->opt & i && f[index])
			f[index](ping, ping->opt_tab[index]);
		i >>= 2;
	}
}
