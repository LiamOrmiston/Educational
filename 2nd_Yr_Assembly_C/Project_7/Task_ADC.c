//*****************************************************************************
//
//	Call assembly language subroutine
//
//		Author: 		Gary J. Minden
//		Organization:	KU/EECS/EECS 388
//		Date:			2014-04-18
//		Version:		1.0
//
//		Purpose:		Call assembly language subroutine and check result
//
//		Notes:
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
#include "driverlib/adc.h"

#include "FreeRTOS.h"
#include "task.h"
#include "stdio.h"
#include "queue.h"

#define SELECT GPIO_PIN_7
static unsigned char origState = SELECT , prevState = SELECT;
xQueueHandle queue2;
//*****************************************************************************
//
//	Task ADCSampler_lab7
//
//*****************************************************************************
void ADCSampler_lab7(void *pvParameters)
{
	//Initialize select button
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
	GPIOPinTypeGPIOInput(GPIO_PORTG_BASE, SELECT);
	GPIOPadConfigSet(GPIO_PORTG_BASE, SELECT, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
	//
	// Enable the GPIO Port D.
	//
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	//
	// Configure GPIO_D<1> to 4ma and sets signal to "high"
	//
	GPIOPinTypeGPIOOutput( GPIO_PORTD_BASE, GPIO_PIN_1 );
	GPIOPadConfigSet(GPIO_PORTD_BASE, GPIO_PIN_1, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_OD);
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x02);

	//ADC Sequencer - Initialization
    SysCtlPeripheralEnable( SYSCTL_PERIPH_ADC0 );
    ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);
    ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_IE | ADC_CTL_END | ADC_CTL_CH1);
    ADCSequenceEnable(ADC0_BASE, 1);
    ADCIntClear(ADC0_BASE, 1);

    unsigned long delay=0;
    unsigned long sample_val_2;
  	while(1)
  	{
  		delay=10;
  		unsigned char currState = GPIOPinRead( GPIO_PORTG_BASE, SELECT );
  		if (currState != SELECT)
  		{
  			if (currState == prevState)
  			{
  				if (currState != origState)
  				{
  				}
  			}
  			else
  			{
  				delay+=90;
  			}
  		}
		else
		{
			if((currState == prevState)&&(currState != origState))
			{
				UARTprintf( "SELECT was pressed \n" );
				//	Discharge
				GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x00);
				vTaskDelay(5);
				//	Charge
				GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x02);
				int keepCount= 0;
				while(keepCount<100)
				{
					keepCount++;
					ADCProcessorTrigger(ADC0_BASE, 1);
					while(!ADCIntStatus(ADC0_BASE, 1, false))
					{ }
					ADCSequenceDataGet(ADC0_BASE, 1, &sample_val_2);
					ADCIntClear(ADC0_BASE, 1);
					xQueueSend(queue2, &sample_val_2, 0);
					SysCtlDelay(16666);
				}
			}
		}
			origState = prevState;
			prevState = currState;
			vTaskDelay(delay);
  	}
}
//*****************************************************************************
//
//	Task ADCDisplay_lab7 -- Receives values from the Queue and prints them on a terminal
//	window by sending messages through PuTTY.
//
//*****************************************************************************
void ADCDisplay_lab7(void *pvParameters)
{
	// Values to be received from the queue will be stored in print_value for printing
	unsigned long print_value=0;

	// UART0 -- Enable
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	
	// UART0 -- Initialization
	UARTStdioInit(0);
	
	// PortD -- Enable
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

	// Printer
	while(1)
	{
		if (queue2 != 0)
		{
			if (xQueueReceive(queue2, &print_value, 250))
			{
				UARTprintf( "%04d\n", print_value);
			}
		}
	}
}
