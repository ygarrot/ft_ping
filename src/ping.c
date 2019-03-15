/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:53:58 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/15 14:03:44 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int		ping_send(t_packet *data, int socket, t_ping *ping)
{
	if (sendto(socket, data,
			   	sizeof(t_packet), 0,
				(t_sockaddr*)ping->sockaddr,
				ping->sockaddr_len ) <= 0) 
	{ 
		perror("sendto");
		ft_exit("\nPacket Sending Failed!\n", EXIT_FAILURE); 
		/* flag=0; */ 
	} 
	return 1;
}

/*
struct iovec {                     Scatter/gather array items 
	void  *iov_base;               Starting address 
	size_t iov_len;                Number of bytes to transfer 
};

struct msghdr {
	void         *msg_name;        optional address 
	socklen_t     msg_namelen;     size of address 
	struct iovec *msg_iov;         scatter/gather array 
	size_t        msg_iovlen;      # elements in msg_iov 
	void         *msg_control;     ancillary data, see below 
	size_t        msg_controllen;  ancillary data buffer len 
	int           msg_flags;       flags on received message 
};
*/

int		ping_receive(int sockfd, t_ping *ping)
{
	struct iovec	iov[1];
	char			buffer[BUFF_S + 1];
	struct msghdr	msg;

	ft_bzero(&msg, sizeof(msg));
	ft_bzero(&iov, sizeof(iov));
	iov[0].iov_base = buffer;
	iov[0].iov_len  = sizeof(buffer);
	msg.msg_name = ping->sockaddr;
	msg.msg_namelen = ping->sockaddr_len;
	msg.msg_iov     = iov;
	msg.msg_iovlen  = 1;
	/* msg.msg_accrights    = (char *)&pass_sd; */
	/* msg.msg_accrightslen = sizeof(pass_sd); */
	if (recvmsg(sockfd, &msg, MSG_WAITALL) < 0)
	{ 
		ft_printf("\nPacket receive failed!\n");
	} 
	return (1);
}

void	send_ping()
{
	return ;
}
