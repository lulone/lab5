/*
 * command_parser_fsm.c
 *
 *  Created on: Dec 14, 2022
 *      Author: HUY
 */

#include "command_parser_fsm.h"

int data_index = 0;
int slot = 0;
char st[50];

void command_parser_fsm_run(void){
	  if (index_buffer == 0)
		  slot = MAX_BUFFER_SIZE - 1;
	  else
	  	  slot = index_buffer - 1;

	  switch(status){
	  	  case INIT:
			  if (buffer[slot] == '!')
				 status = COMMAND_READING;
			  else
	  		  break;
	  	  case COMMAND_READING:
	  		  if (buffer[slot] == '#'){
	  			  for (int i = 0; i < MAX_BUFFER_SIZE; i++)
	  				  buffer[i] = '\0';
	  			  index_buffer = 0;
	  			  data_size = data_index;
	  			  data_index = 0;
	  			  command_flag = 1;
	  			  HAL_UART_Transmit(&huart2, (void *)st, sprintf(st, "\r"), 1000);
	  			  status = INIT;
	  		  }
	  		  else{
				  command_data[data_index++] = buffer[slot];
				  if(data_index == MAX_BUFFER_SIZE)
					 data_index = 0;
//			      HAL_UART_Transmit(&huart2, (void *)st, sprintf(st, "%s\r", command_data), 1000);
	  		  }
	  		  break;
	  	  default:
	  		  break;
	  }
}
