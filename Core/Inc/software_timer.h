/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: HUY
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;

void clearTimer1();
void setTimer1(int duration);
void setTimer2(int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
