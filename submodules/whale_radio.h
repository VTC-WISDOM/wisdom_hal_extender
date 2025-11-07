#ifndef WHALE_RADIO_INTERFACE_H
#define WHALE_RADIO_INTERFACE_H

#include <stddef.h>
#include <stdint.h>

enum w_radio_error {
	W_RADIO_OK,
	W_RADIO_ERROR
};

int w_radio_init(void);
int w_radio_error_get(void);

int w_radio_node_address_set(int node_address);
int w_radio_node_address_get(int *node_address);

int w_radio_subnet_address_set(int sub_address);
int w_radio_subnet_address_get(int *sub_address);

int w_radio_rssi_get(int *rssi);
int w_radio_rtr_count_get(int *rtr_count);

int w_radio_dbm_set(int dbm);

int w_radio_tx(
	int rx_address,
	void *payload_buffer,
	ptrdiff_t buffer_size
);

int w_radio_rx(
	void *payload_buffer,
	ptrdiff_t buffer_size,
	ptrdiff_t *payload_size,
	int *tx_address
);

int w_radio_tx_broadcast(
	void *payload_buffer,
	ptrdiff_t buffer_size
);

int w_radio_rx_broadcast(
	void *payload_buffer,
	ptrdiff_t buffer_size,
	ptrdiff_t *payload_size,
	int *tx_address
);

#endif // WHALE_RADIO_INTERFACE_H
