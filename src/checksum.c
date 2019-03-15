/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:48:47 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/15 20:04:52 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/* unsigned short checksum(void *b, int len) */ 
/* { */
/* 	unsigned short *buf; */ 
/* 	unsigned int sum; */ 
/* 	unsigned short result; */ 

/* 	sum = 0; */
/* 	buf = b; */
/* 	while (len > 1) */ 
/* 	{ */
/* 		sum += *buf++; */ 
/* 		len -= 2; */
/* 	} */
/* 	if (len == 1) */ 
/* 		sum += *(unsigned char*)buf; */ 
/* 	sum = (sum >> 16) + (sum & 0xFFFF); */ 
/* 	sum += (sum >> 16); */ 
/* 	result = ~sum; */ 
/* 	return (result); */ 
/* } */ 

unsigned short checksum(void *b, int len) 
{    unsigned short *buf = b; 
	unsigned int sum=0; 
	unsigned short result; 

	for ( sum = 0; len > 1; len -= 2 ) 
		sum += *buf++; 
	if ( len == 1 ) 
		sum += *(unsigned char*)buf; 
	sum = (sum >> 16) + (sum & 0xFFFF); 
	sum += (sum >> 16); 
	result = ~sum; 
	return result; 
} 
