/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:06:31 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/14 12:58:50 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"


/* int		fill_tcp() */
/* { */
/*   tcph->th_sport = htons (1234);	/1* arbitrary port *1/ */
/*   tcph->th_dport = htons (P); */
/*   tcph->th_seq = random ();/1* in a SYN packet, the sequence is a random *1/ */
/*   tcph->th_flags = TH_SYN;	/1* initial connection request *1/ */
/*   tcph->th_win = htonl (65535);	/1* maximum allowed window size *1/ */
/* } */

#define SRC_ADDR "127.0.0.1"

int		fill_ip(t_ip *iph, t_sockaddr_in sin)
{

  iph->ip_hl = 5;
  iph->ip_v = 4;
  iph->ip_len = sizeof (struct ip) ;
  /* + sizeof (struct tcphdr);	/1* no payload *1/ */
  iph->ip_id = getpid();	/* the value doesn't matter here */
  iph->ip_ttl = 255;
  iph->ip_p = 6;
  iph->ip_src.s_addr = inet_addr(SRC_ADDR);/* SYN's can be blindly spoofed */
  iph->ip_dst.s_addr = sin.sin_addr.s_addr;
  return (1);
}
