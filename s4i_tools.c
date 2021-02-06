/*
 * s4i_tools.c
 *
 *  Created on: 21 fÃ©vr. 2020
 *      Author: francoisferland
 */

#include "s4i_tools.h"
#include "xparameters.h"
#include <stdlib.h>

#include <xgpio.h>

XGpio s4i_xgpio_input_sws;

void s4i_init_hw()
{
    // Initialise l'accï¿½s au matÅ½riel GPIO pour s4i_get_sws_state().
	XGpio_Initialize(&s4i_xgpio_input_sws, XPAR_AXI_GPIO_0_DEVICE_ID);
	XGpio_SetDataDirection(&s4i_xgpio_input_sws, 1, 0xF);
}

int s4i_is_cmd_sws(char *buf)
{


	buf += 5;
	// strncmp(fext, "htm", 3)
	// strcat(buf, "image/jpeg");



	return (!strncmp(buf, "cmd", 3) && !strncmp(buf+4, "sws", 3));

	// return 0;
    // TODO: VÅ½rifier si la chaâ€�ne donnÅ½e correspond Ë† "cmd/sws".
    // Retourner 0 si ce n'est pas le cas.
    // Attention: la chaâ€�ne possï¿½de la requï¿½te complï¿½te (ex. "GET cmd/sws").
    // Un indice : Allez voir les mÅ½thodes similaires dans web_utils.c.
}

unsigned int s4i_get_sws_state()
{
    // Retourne l'Å½tat des 4 interrupteurs dans un entier (un bit par
    // interrupteur).
    return XGpio_DiscreteRead(&s4i_xgpio_input_sws, 1);
}


