/*
 * sercom_usart_config.h
 *
 * Created: 1/23/2018 7:45:03 AM
 *  Author: pvallone
 */ 


#ifndef SERCOM_USART_CONFIG_H_
#define SERCOM_USART_CONFIG_H_


#include <asf.h>
uint8_t usart_read_buffer;

/* Uncomment to use SERCOM 2 / 3 config settings! */
//#define SERCOM2USART
//#define SERCOM3USART // SAMD21 xplained Pro EDBG
#define  SERCOM3USART

#if defined(SERCOM2USART) // SAMD21 xplained pro PA22/PA23
#define SERCOMMODULE	SERCOM2
#define SERCOMMUX		USART_RX_1_TX_0_XCK_1
#define SERCOMPAD0		PINMUX_PA08D_SERCOM2_PAD0
#define SERCOMPAD1		PINMUX_PA09D_SERCOM2_PAD1
#define SERCOMPAD2		PINMUX_UNUSED
#define SERCOMPAD3		PINMUX_UNUSED
#elif defined(SERCOM2M0USART) // SAMD21 Arduino M0 TX/RX PA10/PA11
#define SERCOMMODULE	SERCOM2
#define SERCOMMUX		USART_RX_2_TX_2_XCK_3
#define SERCOMPAD0		PINMUX_UNUSED
#define SERCOMPAD1		PINMUX_UNUSED
#define SERCOMPAD2		PINMUX_PA10D_SERCOM2_PAD2
#define SERCOMPAD3		PINMUX_PA11D_SERCOM2_PAD3
#elif defined(SERCOM3USART) //SAMD21 xplained EDBG
#define SERCOMMODULE	SERCOM3
#define SERCOMMUX		USART_RX_1_TX_0_XCK_1
#define SERCOMPAD0		PINMUX_PA22C_SERCOM3_PAD0
#define SERCOMPAD1		PINMUX_PA23C_SERCOM3_PAD1
#define SERCOMPAD2		PINMUX_UNUSED
#define SERCOMPAD3		PINMUX_UNUSED
#else
#define SERCOMMODULE	SERCOM5 // Arduino M0 Edbg
#define SERCOMMUX		USART_RX_2_TX_2_XCK_3
#define SERCOMPAD0		PINMUX_UNUSED
#define SERCOMPAD1		PINMUX_UNUSED
#define SERCOMPAD2		PINMUX_PB22D_SERCOM5_PAD2
#define SERCOMPAD3		PINMUX_PB23D_SERCOM5_PAD3

#endif

struct usart_module usart_instance;

void configure_console(uint32_t baud);
void serialRead(uint16_t *const buffer);



#endif /* SERCOM_USART_CONFIG_H_ */