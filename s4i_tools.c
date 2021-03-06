/*
 * s4i_tools.c
 *
 *  Created on: 21 fÃ©vr. 2020
 *      Author: francoisferland
 */

#include "s4i_tools.h"
#include "xparameters.h"

#include <xgpio.h>
#include <stdlib.h>

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

int s4i_is_analyse_bpm(char *buf)
{
	return !strncmp(buf, "GET /analyse/bpm", 16);
}

int s4i_is_analyse_zone_cardiaque(char* buf) {
	return !strncmp(buf, "GET /analyse/zone_cardiaque", 27);
}

int s4i_is_analyse_o2(char *buf)
{
	return !strncmp(buf, "GET /analyse/o2", 15);
}

int s4i_is_analyse_etat_sommeil(char *buf)
{
	return !strncmp(buf, "GET /analyse/etat_sommeil", 25);
}

int s4i_is_analyse_activite_physique(char *buf)
{
	return !strncmp(buf, "GET /analyse/activite_physique", 30);
}

unsigned int s4i_get_sws_state()
{
    // Retourne l'Å½tat des 4 interrupteurs dans un entier (un bit par
    // interrupteur).
    return XGpio_DiscreteRead(&s4i_xgpio_input_sws, 1);
}

char* get_mouv_donnee() {

	// Pour l'instant on génère un nombre et on choisi le niveau d'activité selon ce dernier
	int niv_act = rand() % 3;

	if (niv_act == 0) {
		return "Sédentaire";
	} else if (niv_act == 1) {
		return "Activité physique moyenne";
	} else {
		return "Acivité physique intense";
	}

}

char* get_zone_cardiaque() {
	int zone_card = rand() % 4;

	if (zone_card == 0) {
		return "Aucune";
	} else if (zone_card == 1) {
		return "Cardio";
	} else if (zone_card == 2){
		return "Brulure de graisse";
	} else {
		return "Maximale";
	}
}

int get_bpm()
{
	int rythme = rand() % 80 + 50;

	return rythme;
}

int get_o2()
{
	return rand() % 5 + 95;
}

