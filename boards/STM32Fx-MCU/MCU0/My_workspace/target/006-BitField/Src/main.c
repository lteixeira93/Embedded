/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "main.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

static void sleep(int secs);

int main(void)
{
  /* Loop forever */
  RCC_AHB1ENR_t volatile *const pRCC_AHB1ENR = (RCC_AHB1ENR_t*) 0x40023830;
  GPIOx_MODE_t  volatile *const pGPIOx_MODE  = (GPIOx_MODE_t*) 0x40021000;
  GPIOx_ODR_t   volatile *const pGPIOx_ODR   = (GPIOx_ODR_t*) 0x40021014;

  pRCC_AHB1ENR->GPIOE_EN = 1;
  pGPIOx_MODE->MODER1 = 0x01;

  while (1) {
    sleep(2);
    pGPIOx_ODR->ODR1 = 1;
    sleep(2);
    pGPIOx_ODR->ODR1 = 0;
  }
  
	for(;;);
}

static void sleep(int secs) {
  #define STEPS_PER_SEC 650000
  unsigned int i,s;
  for (s=0; s < secs; s++) {
    for (i=0; i < STEPS_PER_SEC; i++) {
       // skip CPU cycle or any other statement(s) for making loop 
       // untouched by C compiler code optimizations
       asm("nop");
    }
  }
}