/*
 * Copyright (C) 2006 BATMAN contributors:
 * Thomas Lopatic, Corinna 'Elektra' Aichele, Axel Neumann, Marek Lindner, Andreas Langer
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 *
 */

// #include <linux/net.h>		/* socket */
// #include <linux/completion.h>	/* completion */

/* io controls */
#define IOCSETDEV 1
#define IOCREMDEV 2

#define TRANSPORT_PACKET_SIZE 29
#define VIP_BUFFER_SIZE 5
#define BATMAN_PORT 4306

#define TUNNEL_DATA 0x01
#define TUNNEL_IP_REQUEST 0x02
#define TUNNEL_IP_INVALID 0x03
#define TUNNEL_KEEPALIVE_REQUEST 0x04
#define TUNNEL_KEEPALIVE_REPLY 0x05

#define LEASE_TIME 300

#define DBG(msg,args...) do { printk(KERN_DEBUG "batgat: [%s:%u] " msg "\n", __func__ ,__LINE__, ##args); } while(0)

struct gw_client {
	uint32_t address;
	unsigned long last_keep_alive;
};

struct batgat_ioc_args {
	char dev_name[IFNAMSIZ];
	unsigned char exists;
	uint32_t universal;
	uint32_t ifindex;
};

struct gate_priv {
	struct socket *tun_socket;
};