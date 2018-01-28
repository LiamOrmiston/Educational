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
// Edited by Brad Torrence 2014-4-7
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"

#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"
#include "Drivers/rit128x96x4.h"
#include "driverlib/adc.h"

#include "FreeRTOS.h"
#include "task.h"
#include "stdio.h"
#include "queue.h"
//*****************************************************************************
//
//	The number of clock cycles between SysTick interrupts. The SysTick interrupt
//	period is 1 mS. All events in the application occur at some fraction of
//	this clock rate.
//
//*****************************************************************************
#define SYSTICK_FREQUENCY		10000
extern volatile int long xPortSysTickCount;
extern void ADCSampler_lab7( void *pvParameters );
extern void ADCDisplay_lab7( void *pvParameters );
extern xQueueHandle queue2;


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

 		vTaskDelay(2500);
 	}
 }

 xQueueHandle queue;

 //*****************************************************************************
 //
 //	Task ADC
 //
 //*****************************************************************************
 void ADC(void *pvParameters){

 	unsigned long ulValue;
 	//
 	//Activate Port D
 	//
 	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
 	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0);
 	GPIOPadConfigSet(GPIO_PORTD_BASE, GPIO_PIN_0, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD);
 	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0x01);
 	//
 	// Sequencer Activation
 	//
 	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
 	//
 	// Sequence 0 Configutation
 	//
 	ADCSequenceConfigure(ADC0_BASE,0, ADC_TRIGGER_PROCESSOR, 0);
 	ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_IE | ADC_CTL_END | ADC_CTL_CH0);
 	//
 	// Enable Sequence 0
 	//
 	ADCSequenceEnable(ADC0_BASE, 0);
 	ADCIntClear(ADC0_BASE, 0);

 	while(1){
 		//
 		// Trigger Sequence 0
 		//
 		ADCProcessorTrigger(ADC0_BASE, 0);
 		//
 		// Do nothing until sampling is complete, i.e. Empty Loop
 		while(!ADCIntStatus(ADC0_BASE, 0, false))
 		{
 		}
 		//
 		// Get data from Sequence 0
 		//
 		ADCSequenceDataGet(ADC0_BASE,0, (void *) &ulValue);
 		ADCIntClear(ADC0_BASE, 0);
 		//
 		// Send the Data to the queue
 		//
 		xQueueSend(queue, (void *) &ulValue,(5000));
 		vTaskDelay(10000);
 	}
 }

 //*****************************************************************************
 //
 //	Task DisplayADC
 //
 //*****************************************************************************
 void DisplayADC(void *pvParameters){

 	char				ADCString[32];
 	portTickType		TaskStartTime;
 	unsigned long theValue;
 	//
 	//	Executed periodically
 	//
     TaskStartTime = xTaskGetTickCount();
     while(1){
     	if (queue != 0)
     	{
     		xQueueReceive(queue, (void *)&theValue, 2500);
     	}
 		sprintf(ADCString, "ADC: %04d", theValue);
 	    RIT128x96x4StringDraw(ADCString, 0, 75, 15);
 	    vTaskDelayUntil(&TaskStartTime, 2500);
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
     //	Set up periodic execution
     //
     TaskStartTime = xTaskGetTickCount();
 	RIT128x96x4Init(1000000);
     while(1){
     	sprintf(TimeString, "Chinmay: %d", xPortSysTickCount);
     	RIT128x96x4StringDraw(TimeString, 24, 16, 15);

 		//sprintf(TimeString, "Time: %d", xPortSysTickCount);
 	   // RIT128x96x4StringDraw(TimeString, 24, 30, 15);
 	    //
 	    // Re-executes after 5000 ticks from the initial start time of the task
 	    //
 		vTaskDelayUntil(&TaskStartTime, 5000);
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
 	// Create queue to pass data between tasks
 	//
 	queue = xQueueCreate(5, sizeof(unsigned long));
 	//
 	// Lab 7 --- A queue to pass data between tasks
 	//
 	queue2 = xQueueCreate(100, sizeof(unsigned long));
 	//
 	//	Create a task to blink LED
 	//
 	xTaskCreate(BlinkLED, (signed portCHAR*) "Blinky", 32, NULL, 1, NULL);
 	//
 	//	Create a task to display string on OLED
 	//
 	xTaskCreate(Display, (signed portCHAR*) "Display", 512, NULL, 1, NULL);
 	//
 	// Create a task to run the ADC
 	//
 	xTaskCreate(ADC, (signed portCHAR*) "ADC", 32, NULL, 1, NULL);
 	//
 	//	Create a task to display the most recent ADC sample
 	//
 	xTaskCreate(DisplayADC, (signed portCHAR*) "ADC_Display", 512, NULL, 1, NULL);
 	//
 	//	Lab 7 --- Create a task to run the ADC
 	//
 	xTaskCreate(ADCSampler_lab7, (signed portCHAR*) "ADC_2", 64, NULL, 1, NULL);
 	//
 	//	Lab 7 --- Create a task to display the most recent ADC sample in the queue on Terminal via PuTTY
 	//
 	xTaskCreate(ADCDisplay_lab7, (signed portCHAR*) "ADCDisplay_lab7", 128, NULL, 1, NULL);
 	//
 	//  Output the start screen
 	//
 	PrintInit();
 	//
 	//	Start FreeRTOS Task Scheduler
 	//
 	vTaskStartScheduler();

 	while(1){}
 }
