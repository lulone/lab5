/*
 * global.h
 *
 *  Created on: Dec 14, 2022
 *      Author: HUY
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <stdio.h>
#include <string.h>
#include "main.h"
#include "software_timer.h"

#define MAX_BUFFER_SIZE  30
#define INIT			 1
#define COMMAND_READING  2

extern int status;
extern int command_flag;
extern char command_data[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern int data_size;

#endif /* INC_GLOBAL_H_ */
