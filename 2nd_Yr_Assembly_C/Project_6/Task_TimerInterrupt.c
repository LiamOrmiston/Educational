#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"

#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"
#include "Drivers/rit128x96x4.h"

#include "FreeRTOS.h"
#include "task.h"

#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "semphr.h"

#include "stdio.h"
#include "driverlib/adc.h"
#include "queue.h"

unsigned long timerCount;
xSemaphoreHandle Timer_0_A_Semaphore;

//*****************************************************************************
//
//	Task Task_TimeOfDay -- Called from main() in Timer_main.c
//
//*****************************************************************************
void Task_TimeOfDay(void *pvParameters){

	unsigned long hour 		= 0;
	unsigned long minute 	= 0;
	unsigned long second 	= 0;
	char	timerString[32];
	//
	//	Generates the semaphore required.
	//
	vSemaphoreCreateBinary(Timer_0_A_Semaphore);
	//
	// Enabling the peripherals
	//
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	//
	// The 32-bit timer is split so it works as 2 16-bit timers
	//
	TimerConfigure(TIMER0_BASE, TIMER_CFG_A_PERIODIC | TIMER_CFG_SPLIT_PAIR );
	TimerPrescaleSet(TIMER0_BASE, TIMER_A, 250);
	TimerLoadSet(TIMER0_BASE, TIMER_A, 2000);
	//
	// Timer_0_A interrupt
	//
	TimerIntEnable( TIMER0_BASE, TIMER_TIMA_TIMEOUT );
	//
	// Timer_0_A interrupt(NVIC)
	//
	IntEnable( INT_TIMER0A);
	TimerEnable(TIMER0_BASE, TIMER_A);
    while(1){
    	//
    	// "Taking" the semaphore indicates that the resource
    	//	is in use. Any more requests to "take" will put the
    	//	requesting thread in queue. A wait time is created in
    	//  the while loop in Timer_0_A_ISR_Handler.
    	//
    	xSemaphoreTake( Timer_0_A_Semaphore, portMAX_DELAY );
		//
    	//	The timerCount is measuring time in ms. 100 ms is
    	//	equivalent to 1 centi second.
    	//
    	if (timerCount == 100){
			//	Restart the timerCount and increase seconds
			second= second+1;
			timerCount = 0;
			// 60 seconds are equivalent to a minute. Seconds
			// are reset to 0 and minutes are increased by one.
			if (second == 60)
			{
				minute= minute+1;
				second = second - 60;
				// 60 minutes are equivalent to an hour. Minutes
				// are reset to 0 and hours are increased by one.
				if (minute == 60)
				{
					hour= hour+1;
					minute = minute- 60;
				}
			}
		}
		sprintf(timerString, "Time: %02d:%02d:%02d:%02d", hour, minute, second, timerCount);
	    RIT128x96x4StringDraw(timerString, 25, 65, 15);
	}
}

//*****************************************************************************
//
//	Task Timer_0_A_ISR_Handler -- Referenced from startup_ccs.c
//*****************************************************************************
void Timer_0_A_ISR_Handler(void)
{
	portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;
	//
	// "Give" the Timer_0_A_Semaphore
	//
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	timerCount++;
	xSemaphoreGiveFromISR( Timer_0_A_Semaphore,
	&xHigherPriorityTaskWoken );
	//
	// If xHigherPriorityTaskWoken was set to true,
	// we should yield. The actual macro used here is
	// port specific.
	//
	if ( xHigherPriorityTaskWoken ) {
		vPortYieldFromISR( );
	}

}
