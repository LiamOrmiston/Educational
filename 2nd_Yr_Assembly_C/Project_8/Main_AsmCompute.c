//*****************************************************************************
//
//	FreeRTOS Demo
//
//		Blink the LED
//
//		Author: 		Gary J. Minden
//		Organization:	KU/EECS/EECS 388
//		Date:			2013-04-19
//		Version:		1.0
//
//		Purpose:		Example program that demonstrates:
//							(1) setting up a GPIO pin (LED)
//							(2) blinking (toggling) a LED
//
//		Notes:			Updated at KU and adapted from the TI LM3S1968 blinky
//						and other examples.
//
//*****************************************************************************
// Edited by Brad Torrence 2014-4-21

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"

#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"
#include "Drivers/rit128x96x4.h"
#include "Drivers/uartstdio.h"

#include "FreeRTOS.h"
#include "task.h"

#include "stdio.h"

//*****************************************************************************
//
//	The number of clock cycles between SysTick interrupts. The SysTick interrupt
//	period is 1 mS. All events in the application occur at some fraction of
//	this clock rate.
//
//*****************************************************************************
#define SYSTICK_FREQUENCY configTICK_RATE_HZ

extern volatile int long xPortSysTickCount;

extern void Task_AsmCompute( void *pvParameters );

//*****************************************************************************
//
//	Task to output Initial screen.
//
//*****************************************************************************
void PrintInit(){
    //
	// 	Code to cause a wait for a "Select Button" press
    //
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
	GPIOPinTypeGPIOInput(GPIO_PORTG_BASE, GPIO_PIN_7);
    GPIOPadConfigSet(GPIO_PORTG_BASE, GPIO_PIN_7, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
	RIT128x96x4Init(1000000);
	RIT128x96x4StringDraw("FreeRTOS starting\n", 8, 0, 15);
	RIT128x96x4StringDraw("Press \"Select\" Button", 0, 24, 15);
	RIT128x96x4StringDraw("To Continue", 32, 32, 15);
	while(GPIOPinRead(GPIO_PORTG_BASE, GPIO_PIN_7));
	SysCtlPeripheralReset(SYSCTL_PERIPH_GPIOG);
	SysCtlPeripheralDisable(SYSCTL_PERIPH_GPIOG);
    //
    // Enable UART0, to be used as a serial console.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    UARTStdioInit( 0 );
    UARTprintf( "FreeRTOS LM3S1968 starting\n" );
}

//*****************************************************************************
//
//	Task to blink the LED
//
//*****************************************************************************
void BlinkLED(void *pvParameters){
    //
    // Enable the GPIO Port G.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);

    //
    // Configure GPIO_G to drive the Status LED.
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_2);
    GPIOPadConfigSet(GPIO_PORTG_BASE, GPIO_PIN_2, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

	unsigned long LED_Data = 0;

	while(1){
		//
	 	// Toggle the LED.
		//
		LED_Data = GPIOPinRead(GPIO_PORTG_BASE, GPIO_PIN_2);
		LED_Data = LED_Data ^ 0x04;
		GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_2, LED_Data);

		vTaskDelay(50);
	}
}

//*****************************************************************************
//
//	Task to Display the systick count
//
//*****************************************************************************
void Display(void *pvParameters){

	char				TimeString[32];
	portTickType		TaskStartTime;

    //
    //	Initialize the OLED display and write status.
    //
	RIT128x96x4Clear();
    RIT128x96x4StringDraw("FreeRTOS_Blinky", 8, 0, 8);

    //
    //	Set up periodic execution
    //
    TaskStartTime = xTaskGetTickCount();

    while(1){
		sprintf(TimeString, "Time: %d", xPortSysTickCount);
	    RIT128x96x4StringDraw(TimeString, 24, 16, 15);

		vTaskDelayUntil(&TaskStartTime, 500);
	}
}

//*****************************************************************************
//
//	Main
//
//*****************************************************************************
int main(void) {
    //
    // Set the clocking to run directly from the crystal.
    //
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);

	//
	//	Create a task to blink LED
	//
	xTaskCreate(BlinkLED, (signed portCHAR*) "Blinky", 32, NULL, 1, NULL);

	//
	//	Create a task to display string on OLED
	//
	xTaskCreate(Display, (signed portCHAR*) "Display", 512, NULL, 1, NULL);

	//
	//	Create a task to test Assembly code
	//
	xTaskCreate(Task_AsmCompute, (signed portCHAR*) "AsmCompute", 512, NULL, 1, NULL);

	//
	//  Output the start screen
	//
	PrintInit();

	//
	//	Start FreeRTOS Task Scheduler
	//
	vTaskStartScheduler();

	while ( 1 ) {}
}

