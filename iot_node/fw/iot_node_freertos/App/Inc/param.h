#ifndef __PARAM_H__
#define __PARAM_H__

#include <stdio.h>
#include <stdint.h>
#include  "epprom.h"

/* Default config
 * */
#define NODE_ID_ADR_DEFAULT				1
/* Modbus salve parameters---*/
#define NODE_MB_ID_DEFAULT				1
#define NODE_MB_SERCFG_DEFAULT			1
#define NODE_MB_MODE_DEFAULT			1  //RTU OR ASCII
#define NODE_MB_BAUD_DEFAULT			1
#define NODE_MB_DATABITS_DEFAULT		1
#define NODE_MB_PARTITY_DEFAULT			1
#define NODE_MB_STOPBITS_DEFAULT		1

#define NODE_LRWAN_DATARATE_DEFAULT 	0
#define NODE_LRWAN_CLASS_DEFAULT		2
#define NODE_LRWAN_FREQ_DEFAULT			0
#define NODE_LRWAN_CONFIRM_DEFAULT		1
#define NODE_LRWAN_MODE_DEFAULT			0
#define NODE_LRWAN_TX_POWER_DEFAULT 	0  // max
#define NODE_LRWAN_AUTO_JOIN_DEFAULT    0

#define NODE_IO_PORT_0_DEFAULT			0
#define NODE_IO_PORT_1_DEFAULT			1
#define NODE_IO_PORT_2_DEFAULT			2
#define NODE_IO_PORT_3_DEFAULT			2
#define NODE_IO_PORT_4_DEFAULT			4
#define NODE_IO_PORT_5_DEFAULT			5
#define NODE_IO_PORT_6_DEFAULT			6



/**
 *
 *
 *
 * */
/* Salve parameters---*/
#define NODE_HAVE_PARAM_ADR			0
#define NODE_ID_ADR					1
/* Modbus salve parameters---*/
#define NODE_MB_ID_ADR				2
#define NODE_MB_SERCFG_ADR 			3
#define NODE_MB_MODE_ADR			4  //RTU OR ASCII
#define NODE_MB_BAUD_ADR			5
#define NODE_MB_DATABITS_ADR		6
#define NODE_MB_PARTITY_ADR			7
#define NODE_MB_STOPBITS_ADR		8
#define NODE_MB_WORKMODE_ADR		9 // 0: Slave 1: Master
#define NODE_MB_DEFAULT_LEN


/* LoRa parameters---*/
/**/
#define NODE_LRWAN_BASE 			20

#define NODE_LRWAN_WORKMODE_ADR		NODE_LRWAN_BASE + 0  //// 0: LoRaWAN 1: LoRa
#define NODE_LRWAN_WORKMODE_LEN		1

#define NODE_LRWAN_DATARATE_ADR		NODE_LRWAN_WORKMODE_ADR + NODE_LRWAN_WORKMODE_LEN
#define NODE_LRWAN_DATARATE_LEN		1

#define NODE_LRWAN_CLASS_ADR		NODE_LRWAN_DATARATE_ADR + NODE_LRWAN_DATARATE_LEN
#define NODE_LRWAN_CLASS_LEN		1

#define NODE_LRWAN_FREQ_ADR			NODE_LRWAN_CLASS_ADR + NODE_LRWAN_CLASS_LEN
#define NODE_LRWAN_FREQ_LEN			1

#define NODE_LRWAN_CONFIRM_ADR		NODE_LRWAN_FREQ_ADR +NODE_LRWAN_FREQ_LEN
#define NODE_LRWAN_CONFIRM_LEN		1

#define NODE_LRWAN_TX_POWER_ADR		NODE_LRWAN_CONFIRM_ADR + NODE_LRWAN_CONFIRM_LEN
#define NODE_LRWAN_TX_POWER_LEN		1

#define NODE_LRWAN_AUTO_JOIN_ADR	NODE_LRWAN_TX_POWER_ADR +NODE_LRWAN_TX_POWER_LEN
#define NODE_LRWAN_AUTO_JOIN_LEN    1

#define NODE_LRWAN_MODE_ADR			NODE_LRWAN_AUTO_JOIN_ADR +NODE_LRWAN_AUTO_JOIN_LEN
#define NODE_LRWAN_MODE_LEN			1

#define NODE_LRWAN_DEVEUI_ADR		NODE_LRWAN_MODE_ADR + NODE_LRWAN_MODE_LEN
#define NODE_LRWAN_DEVEUI_LEN		8

#define NODE_LRWAN_APPKEY_ADR		NODE_LRWAN_DEVEUI_ADR + NODE_LRWAN_DEVEUI_LEN
#define NODE_LRWAN_APPKEY_LEN 		16

#define NODE_LRWAN_APPEUI_ADR		NODE_LRWAN_APPKEY_ADR + NODE_LRWAN_APPKEY_LEN
#define NODE_LRWAN_APPEUI_LEN 		8


/* IO define **/
#define NODE_IO_BASE				NODE_LRWAN_APPEUI_ADR + NODE_LRWAN_APPEUI_LEN
 /* Param: ADR + TIME_INTERVAL*/
#define NODE_IO_PORT_0_ADR			NODE_IO_BASE + 0
#define NODE_IO_PORT_0_LEN			2

#define NODE_IO_PORT_1_ADR			NODE_IO_PORT_0_ADR + NODE_IO_PORT_0_LEN
#define NODE_IO_PORT_1_LEN			2

#define NODE_IO_PORT_2_ADR			NODE_IO_PORT_1_ADR + NODE_IO_PORT_1_LEN
#define NODE_IO_PORT_2_LEN			2

#define NODE_IO_PORT_3_ADR			NODE_IO_PORT_2_ADR + NODE_IO_PORT_2_LEN
#define NODE_IO_PORT_3_LEN			2

#define NODE_IO_PORT_4_ADR			NODE_IO_PORT_3_ADR + NODE_IO_PORT_3_LEN
#define NODE_IO_PORT_4_LEN			2

#define NODE_IO_PORT_5_ADR			NODE_IO_PORT_4_ADR + NODE_IO_PORT_4_LEN
#define NODE_IO_PORT_5_LEN			2

typedef struct
{
	uint8_t uAdr;
	uint8_t uLen;
} uParam_t;

enum{
	NO_PARAM,
	EEP_PARAM,
	FLASH_PARAM
};
enum{
	LR_WAN,
	LR_NONE,
	LR_DISABLE
};
enum{
	MB_SLAVE,
	MB_MASTER,
	MB_DISABLE
};
/*
 *
 * */

#define PARAM_MAX_SIZE 			192
#define PARAM_LOAD_ALL			0xFFFF



extern uint8_t PARAM[EEP_MAX_SIZE];


uint8_t u_mem_get(uint16_t usAdr);
void u_mem_set(uint16_t usAdr, uint8_t uVal);
void v_epr_load(uint16_t usAdr);
void v_epr_save(uint16_t usAdr);

#endif

