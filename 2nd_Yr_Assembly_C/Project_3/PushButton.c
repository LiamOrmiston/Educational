//*****************************************************************************
//
//	blinky.c - Blink the LED and display number of SysTicks
//
//		Author: 		Gary J. Minden
//		Organization:	KU/EECS/EECS 388
//		Date:			2012-08-23
//		Version:		1.0
//
//		Purpose:		Example program that demonstrates:
//							(1) setting up the SysTick Timer and interrupt
//							(2) setting up a GPIO pin (LED)
//							(3) setting up the OLED display
//							(4) drawing on the OLED
//							(5) blinking (toggling) a LED
//							(6) formatting and displaying a number on the OLED
//

//		Notes:			Updated at KU and adapted from the TI LM3S1968 blinky
//						and other examples.
//
//*****************************************************************************
// Edited by Brad Torrence 2014-1-23

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"
#include "drivers/rit128x96x4.h"

#include "stdio.h"
#include "uartstdio.h"
#include "uartstdio.c"

//*****************************************************************************
//
//	The number of clock cycles between SysTick interrupts. The SysTick interrupt
//	period is 0.1 mS. All events in the application occur at some fraction of
//	this clock rate.
//
//*****************************************************************************
#define SYSTICK_FREQUENCY		10000

//*****************************************************************************
//
// The speed of the processor clock in Hertz, which is therefore the speed of the
// clock that is fed to the peripherals.
//
//*****************************************************************************
unsigned long systemClock;

//*****************************************************************************
//
// The number of SysTick clock ticks that have occurred.
//
//*****************************************************************************
static unsigned long sysTickCount = 0;

//*****************************************************************************
//
// Handles the SysTick interrupt.
//
//*****************************************************************************
void SysTickIntHandler(void) {
    //
    // Increment the tick count.
    //
    sysTickCount++;
}

//*****************************************************************************
//
//	Initializes the hardware's system clock and the SysTick Interrupt
//
//*****************************************************************************
void SysTickInit() {
    //
    // Set the clocking to run directly from the crystal.
    //
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);

	//
	// Get the system clock speed.
	//
	systemClock = SysCtlClockGet();

    //
    // Configure SysTick interrupts
    //
    SysTickPeriodSet(systemClock / SYSTICK_FREQUENCY);
    SysTickIntEnable();
    SysTickEnable();
	
    //
	// 	Code to cause a wait for a "Select Button" press
    //
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
	GPIOPinTypeGPIOInput(GPIO_PORTG_BASE, GPIO_PIN_7);
	RIT128x96x4Init(1000000);
	RIT128x96x4StringDraw("Press \"Select\" Button", 0, 24, 15);
	RIT128x96x4StringDraw("To Continue", 32, 32, 15);
	while(GPIOPinRead(GPIO_PORTG_BASE, GPIO_PIN_7));
	SysCtlPeripheralDisable(SYSCTL_PERIPH_GPIOG);
	SysCtlPeripheralReset(SYSCTL_PERIPH_GPIOG);

}

//*****************************************************************************
//
// Task to Blink the on-board LED.
//
//*****************************************************************************

// _Next is the next execution tick for the task (increases with each execution)
// _Delta is the ticks between each execution (constant through each execution)
static unsigned long speakerNext = 0;
static unsigned long speakerDelta1 = 1;
static unsigned long speakerDelta2 = 1;
static unsigned long freq = 0;
static unsigned long buzzFreq1 = 440;
static unsigned long buzzFreq2 = 808;
static unsigned long blinkNext = 0;
static unsigned long blinkDelta = 2500; // The number of sysTicks between executions

static unsigned char origState= Buttons, prevState= Buttons;
static unsigned long buttonNext = 0, buttonDelta = 10;
/*
 * 	_Delta / SYSTICK_FREQUENCY = period in seconds
 * 	500 / 10000 = 0.05 s = 50 ms
 *	The LED will change state every 50 ms
 *
 **************	EDITS*********************
 *	Edited the blinkDelta Value to 2500.
 *	i.e. 2500/10000 = 0.25 = 250 ms.
 *****************************************
 */

void speakerInit()
{
	 //
	 // Enable the GPIO Port H.
	 //
	 SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOH );
	 //
	 // Configure GPIO_H to drive the Speaker.
	 //
	 GPIOPinTypeGPIOOutput( GPIO_PORTH_BASE, GPIO_PIN_1 | GPIO_PIN_0 );
	 GPIOPadConfigSet( GPIO_PORTH_BASE,GPIO_PIN_1 | GPIO_PIN_0,GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU );
	 //
	 // Set PortH<0> ON and PortH<1> OFF.
	 //
	 GPIOPinWrite( GPIO_PORTH_BASE, GPIO_PIN_1 | GPIO_PIN_0, 0x01 );
	 //
	 // The initial time to execute is Delta SysTicks from now.
	 //
	speakerDelta1 = (SYSTICK_FREQUENCY/(2*buzzFreq1));
	speakerDelta2 = (SYSTICK_FREQUENCY/(2*buzzFreq2));
	freq= speakerDelta1;
	speakerNext = sysTickCount + freq;


}

void speakerExecute()
{

	if(sysTickCount >= speakerNext) {
			unsigned long speaker_data = 0;

	        //
	        // Toggle the Pins.
	        //
			speaker_data = GPIOPinRead(GPIO_PORTH_BASE, GPIO_PIN_1 | GPIO_PIN_0 );
			speaker_data = speaker_data ^ 0x03;
	        GPIOPinWrite( GPIO_PORTH_BASE, GPIO_PIN_1 |GPIO_PIN_0,  speaker_data );
	        //
	        //	Advance next execution time.
	        //
	        if((sysTickCount / 7500) % 2 == 0)
	        {
	        	if(freq == speakerDelta1)
	        	{
	        		freq = speakerDelta2;
	        	}
	        	else
	        	{
	        		freq = speakerDelta1;
	        	}

	        }
	        speakerNext = sysTickCount+freq;
		}
}



void BlinkInit() {
    //
    // Enable the GPIO Port G.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);

    //
    // Configure GPIO_G to drive the Status LED.
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_2);
    GPIOPadConfigSet(GPIO_PORTG_BASE, GPIO_PIN_2, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    //
	//	The initial time to execute is 50 ms from now.
    //
    blinkNext = sysTickCount + blinkDelta;
}

void BlinkExecute() {
	if(sysTickCount >= blinkNext) {
		unsigned long led_data = 0;
        //
        // Toggle the LED.
        //
		led_data = GPIOPinRead( GPIO_PORTG_BASE, GPIO_PIN_2 );
		led_data = led_data ^ 0x04;
        GPIOPinWrite( GPIO_PORTG_BASE, GPIO_PIN_2, led_data );

        //
        //	Advance next execution time.
        //
        blinkNext += blinkDelta;
	}
}

//*****************************************************************************
//
// Task to update the OLED display.
//
//*****************************************************************************

static unsigned long tickDisplayNext = 0;
static unsigned long tickDisplayDelta = 5000; // 5000 systicks

void TickDisplayInit() {
    //
    // Initialize the OLED display and write status.
    //
    RIT128x96x4Init(1000000);

    //
	//	The initial time to execute is Delta SysTicks from now.
    //
    tickDisplayNext = sysTickCount + tickDisplayDelta;
}

void TickDisplayExecute()
{
	if(sysTickCount >= tickDisplayNext)
	{
		char count_string[24];
		//
		//  Save the tick count into a string
		//
		sprintf(count_string, "Chinmay: %d", sysTickCount);

		/*
		 * ****************** EDITS ************************
		 * Changed the display text from "Blinky:" to my
		 * first name, "Chinmay:"
		 * */

		//
		//  Draw the tick count string on the OLED display
		//
	    RIT128x96x4StringDraw(count_string, 16, 0, 15);

        //
        //	Advance next execution time
        //
	    tickDisplayNext += tickDisplayDelta;
	}
}

void buttonInit()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);

}

//*****************************************************************************
//
//	Main program to initialize hardware and execute Tasks.
//
//*****************************************************************************
int main( void )  {
	//
	//  Initialize the system clock and systick interrupt
	//
	SysTickInit();
	
    //
    //	Task Initializations
    //
    BlinkInit();
    TickDisplayInit();
    speakerInit();
    buttonInit();

    //
    //	Task Execution
    //
    while (1) {
    	BlinkExecute( );
    	TickDisplayExecute( );
    	speakerExecute();
    }
}
