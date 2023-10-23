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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

extern void initialise_monitor_handles(void);

int g_data_1 = -4000;
int g_data_2 = 200;

int result = 0;

int main(void)
{
	initialise_monitor_handles();
	printf("Size of Types\n");
	printf("char: %d\n", sizeof(char));
	printf("short: %d\n", sizeof(short));
	printf("int: %d\n", sizeof(int));	
	printf("long: %d\n", sizeof(long));

	result = g_data_1 + g_data_2;
	printf("Result = %d\n", result);


	float number = 45.48204378265;
	printf("Result = %0.2f\n", number);
	printf("Result = %0.2e\n", number);

	double chargeE = 1.60217662e-19;
	printf("Result = %0.8lf\n", chargeE);
	printf("Result = %0.8le\n", chargeE);

	int a = 0, b = 0, c = 0;

	scanf("%d", a);
	scanf("%d", b);
	scanf("%d", c);

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);

	uint32_t *pRCCRegAddress       = (uint32_t*) 0x40023830;
	uint32_t *pGPIOAModeRegAddress = (uint32_t*) 0x40020000;
	uint32_t *pGPIOAOutRegAddress  = (uint32_t*) 0x40020014;

	/* Enabling clock for GPIOA peripheral in AHB1ENR register pg 242 */

	/* Debug mode */
	// uint32_t temp = *pRCCRegAddress; // Read
	// temp |= 0x01;                    // Safe modify
	// *pRCCRegAddress = temp;          // Write back

	/* Shorthand mode */
	*pRCCRegAddress |= 0x01;

	/* Configuring mode for GPIOA 6 pin as output (01) pg 281 */
	// First clear 12, 13 bit
	*pGPIOAModeRegAddress &= 0xFFFFCFFF;
	// Then set 12, 13
	*pGPIOAModeRegAddress |= 0x01000;

	/* Configuring output for pin 6 pg 283 */
	*pGPIOAOutRegAddress | 0x40;

    /* Loop forever */
	for(;;);
}