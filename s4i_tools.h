/*
 * s4i_tools.h
 *
 *  Created on: 21 févr. 2020
 *      Author: francoisferland
 */

#ifndef SRC_S4I_TOOLS_H_
#define SRC_S4I_TOOLS_H_

#define S4I_NUM_SWITCHES	4

void			s4i_init_hw();
int 			s4i_is_cmd_sws(char *buf);
int				is_cmd_mouv(char *buf);
unsigned int 	s4i_get_sws_state();
unsigned int	get_donne_mouv();


#endif /* SRC_S4I_TOOLS_H_ */
