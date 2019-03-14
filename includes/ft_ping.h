/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:53:58 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/14 16:48:03 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
#define FT_PING_H

#include "debug.h"
#include "../libft/includes/libft.h"

#include <sys/socket.h>
# include <sys/types.h>

# include <sys/uio.h>

# include <unistd.h>

# include <sys/mman.h>

# include <sys/time.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/ip.h>
#include <netinet/ip_icmp.h>

#define BUFF_S 23
#define PACKETSIZE 64
# define SEND_ERROR "ERROR SEND ERROR\n"
# define RECV_ERROR "ERROR RECV ERROR\n"
# define REQUEST_OK "OK\n"
# define REQUEST_ERROR "ERROR\n"
# define CLOSE_ERROR "ERROR ON CLOSE\n"
# define OPEN_ERROR "ERROR NO SUCH FILE OR DIRECTORY\n"
# define OOM_DEVICE "ERROR NO SPACE LEFT ON DEVICE\n"
# define PIPE_ERR "ERROR ON PIPE\n"
# define FORK_ERR "ERROR ON FORK\n"
# define CLOSE_ERR "ERROR ON CLOSE\n"
# define EXECV_ERR "ERROR ON EXECV\n"
# define READ_ERR "ERROR ON READ\n"
# define BIND_ERROR "ERROR BIND ERROR\n"
# define SOCKET_ERROR "ERROR SOCKET ERROR\n"
# define ERROR_CODE -1



typedef struct timeval	t_timeval;
typedef struct timezone	t_timezone;
typedef struct sockaddr	t_sockaddr;
typedef struct sockaddr6	t_sockaddr6;
typedef struct sockaddr_in6	t_sockaddr_in6;
typedef struct sockaddr_in	t_sockaddr_in;
typedef struct protoent	t_protoent;
typedef struct ip	t_ip;
typedef struct tcphdr t_tcphdr;
typedef struct icmphdr t_icmphdr;
typedef struct hostent t_hostent;
int				ip_version(const char *src);


typedef struct	s_packet
{
	t_icmphdr	hdr;
	char msg[PACKETSIZE - sizeof(t_icmphdr)];
}				t_packet;

/* int		ping_send(void *data, int socket); */

typedef struct s_ping
{
	t_timeval	start_time;
	t_timeval	end_time;
	t_sockaddr_in	sockaddr;
	t_hostent	*host_entity; 
	t_packet	packet;
	char		*host_name;
	int			socket;
	int		sockaddr_len;
	int		active;
	int		port;
}		t_ping;

int		ping_send(t_packet *data, int socket, t_sockaddr_in *ping_addr);
unsigned short checksum(void *b, int len) ;
int		set_packet(t_packet *pckt);
int				set_socket(int is_ipv4);
t_sockaddr		*get_sock_addr(char *addr, int port, int is_serv);
t_sockaddr_in6	*get_ipv6_addr(char *address, int port, t_sockaddr_in6 *ss);
t_sockaddr_in	*get_ipv4_addr(char *address, int port, t_sockaddr_in *ss, int addrtype);
int		ping_receive(int sockfd);
int		ping_loop(t_ping *ping);
int	check_addr(t_ping *ping);

#endif
