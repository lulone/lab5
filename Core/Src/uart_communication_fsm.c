/*
 * uart_communication_fsm.c
 *
 *  Created on: Dec 14, 2022
 *      Author: HUY
 */

#include "uart_communication_fsm.h"

char sr[50];
uint32_t ADC_value = 0;

void clear_cmdData(){
  for (int i = 0; i < data_size; i++)
	  command_data[i] = '\0';
}

void uart_communication_fsm_run(){
  if (command_flag == 1){
	  if (strcmp(command_data, "RTS") == 0){
		  HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		  HAL_ADC_Start(&hadc1);
		  HAL_ADC_PollForConversion(&hadc1, 4000);
		  ADC_value = HAL_ADC_GetValue(&hadc1);
		  HAL_ADC_Stop(&hadc1);
		  HAL_UART_Transmit(&huart2, (void *)sr, sprintf(sr, "!ADC%lu#\r", ADC_value), 1000);

		  clear_cmdData();
		  command_flag = 0;
		  setTimer1(300);
	  }
	  else if(strcmp(command_data, "OK") == 0){
		  HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		  clearTimer1();
		  clear_cmdData();
		  ADC_value = 0;
		  command_flag = 0;
	  } else{
		  clear_cmdData();
		  command_flag = 0;
	  }
  } else if(command_flag == 0 && timer1_flag == 1){
	  HAL_UART_Transmit(&huart2, (void *)sr, sprintf(sr, "!ADC%lu#\r", ADC_value), 1000);
	  setTimer1(300);
  }
}
