/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:53:58 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/16 15:44:37 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
#define FT_PING_H

#include "debug.h"
#include "../libft/includes/libft.h"

#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
# include <sys/types.h>

# include <sys/uio.h>

#include <signal.h>

# include <unistd.h>

# include <sys/mman.h>

# include <sys/time.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/ip.h>
#include <netinet/ip_icmp.h>

#define PING_BAD_COUNT "ping: bad number of packets to transmit."
#define BUFF_S 1500
#define PACKET_SIZE_DEFAULT 64
#define DEFAULT_TIMEOUT 1
#define DEFAULT_DELAY 1.0
#define TTL_DEFAULT 64
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

#define OPT_STR "cdinqsStTvwWh"

enum {
	COUNT = (1 << 0),
	DEBUG = (1 << 1),
	INTERVALE = (1 << 2),
	NUMERIC = (1 << 3),
	QUIET = (1 << 4),
	PACKET_SIZE = (1 << 5),
	SNDBUFF = (1 << 6),
	TTL = (1 << 7),
	TIMESTAMP = (1 << 8),
	VERBOSE = (1 << 9),
	DEADLINE = (1 << 10),
	TIMEOUT = (1 << 11),
	HELP = (1 << 12)
};

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
typedef struct addrinfo	t_addrinfo;
int				ip_version(const char *src);


typedef struct	s_packet
{
	t_icmphdr	hdr;
	/* char		*msg; */
	char		msg[PACKET_SIZE_DEFAULT - sizeof(t_icmphdr)];
}				t_packet;

/* int		ping_send(void *data, int socket); */

typedef struct s_packet_stat
{
	int		size;
	int		send;
	int		rcv;
	int		count;
	int		count_max;
	int		sndbuff;
}				t_packet_stat;
#define PORT_TMP 12

typedef struct s_time_stat
{
	t_timeval	start;
	t_timeval	current;
	long double			intervale;
	long double			delay;
	long double			min;
	long double			avg;
	long double			max;
	long double			mdev;
	int					ttl;
	long double			all;
	int					count;
	int					deadline;
	int					timeout;
}				t_time_stat;

typedef struct	s_ping
{
	t_sockaddr		*sockaddr;
	t_addrinfo		*host_entity; 
	t_packet		packet;
	t_packet_stat	pstat;
	t_time_stat		tstat;
	char			*opt_tab[HELP + 1];
	int				opt;
	char			host_addr[100];
	char			dns_addr[NI_MAXHOST];
	char			*host_name;
	int				socket;
	int				sockaddr_len;
	int				port;
}				t_ping;

extern t_ping *g_ping;
void	stop_loop(int signal);
void	ping_ctor(t_ping *ping);
void	ping_dtor(t_ping *ping);
void	func_tab(t_ping *ping);
void	set_intervale(t_ping *ping, char *value);
void	set_timeout(t_ping *ping, char *value);
void	set_deadline(t_ping *ping, char *value);
void	set_packetsize(t_ping *ping, char *value);
void	set_countmax(t_ping *ping, char *value);
void	set_sndbuff(t_ping *ping, char *value);
void	set_ttl(t_ping *ping, char *value);
void	display_help(t_ping *ping, char *value);

int		set_time_stat(t_ping *ping);
int	print_ping(t_ping *ping);
int	print_stat(t_ping *ping);
double timeval_to_double(t_timeval last_time, t_timeval current_time);
int		ping_send(t_packet *data, int socket, t_ping *ping);
unsigned short checksum(void *b, int len) ;
int		set_packet(t_packet *pckt, t_ping *ping);
int				set_socket(int is_ipv4);
t_sockaddr		*get_sock_addr(char *addr, int port, int is_serv);
t_sockaddr_in6	*get_ipv6_addr(char *address, int port, t_sockaddr_in6 *ss);
t_sockaddr_in	*get_ipv4_addr(char *address, int port, t_sockaddr_in *ss, int addrtype);
int		ping_receive(int sockfd, t_ping *ping);
int		ping_loop(t_ping *ping);
int	check_addr(t_ping *ping);
double intervale(void);
int wait_for (double sec);
int	print_summary(t_ping *ping);
int		reverse_dns_lookup(t_ping *ping);

#endif
