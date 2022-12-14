/*
 * global.c
 *
 *  Created on: Dec 14, 2022
 *      Author: HUY
 */
#include "global.h"

char command_data[MAX_BUFFER_SIZE];
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
int command_flag = 0;
int status = 0;
int data_size = 0;

