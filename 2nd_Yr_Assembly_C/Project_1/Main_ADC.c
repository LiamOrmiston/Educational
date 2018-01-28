#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"
#include "Drivers/rit128x96x4.h"
#include "driverlib/adc.h"
#include "drivers/uartstdio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stdio.h"
#define SYSTICK_FREQUENCY		10000
unsigned long systemClock;
static unsigned long sysTickCount = 0;
static unsigned char flag = 0;
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
//	Task to output Initial screen.
//
//*****************************************************************************
void PrintInit(){
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
  	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
	GPIOPinTypeGPIOInput(GPIO_PORTG_BASE, GPIO_PIN_7);
    GPIOPadConfigSet(GPIO_PORTG_BASE, GPIO_PIN_7, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
	RIT128x96x4Init(1000000);
	RIT128x96x4StringDraw("Math Extravaganza\n", 8, 0, 15);
	RIT128x96x4StringDraw("Press \"Select\" Button", 0, 24, 15);
	RIT128x96x4StringDraw("To Continue", 32, 32, 15);
	RIT128x96x4StringDraw("Left  : True", 2, 62, 15);
	RIT128x96x4StringDraw("Right : False", 2, 72, 15);
	while(GPIOPinRead(GPIO_PORTG_BASE, GPIO_PIN_7));
	SysCtlPeripheralReset(SYSCTL_PERIPH_GPIOG);
	SysCtlPeripheralDisable(SYSCTL_PERIPH_GPIOG);
}


// _Next is the next execution tick for the task (increases with each execution)
// _Delta is the ticks between each execution (constant through each execution)
static unsigned long blinkNext = 0;
static unsigned long blinkDelta = 2500; // The number of sysTicks between executions
/*
 * 	_Delta / SYSTICK_FREQUENCY = period in seconds
 * 	500 / 10000 = 0.05 s = 50 ms
 *	The LED will change state every 50 ms
 *
 */
void BlinkInit() {

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
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
 //	The game algorithm
 //*****************************************************************************
 void game(void *pvParameters){

	unsigned char origState = 0;
	unsigned char prevState = 0;
	//detect where the joystick is being pushed.
	unsigned long delay=0;
	RIT128x96x4Init(1000000);

	// MUST BE OUTSIDE OF THE WHILE LOOOOOOOOOOOP!!!!!
	int score = 200;
	int turn = 0;
	const char* disp_score;
	char	screen_disp[256];

	while(1)
	{
			delay=10;
			// Check if the user has finished playing all the rounds
			if(turn >= 10){
				disp_score = (char*)(((int)'0')+score);
				sprintf(screen_disp, "Score :\n %d", disp_score );
				RIT128x96x4StringDraw("Game over! :-)", 24, 36, 15);
				RIT128x96x4StringDraw(screen_disp, 24, 16, 15);
				vTaskDelay(500000);
				return;
			}else{
				turn= turn + 1;
			}

			// Game variables for equation generation
			int rand(void);
			int true_false = rand() % 2;
			int val1, val2, res;

			//Decide if the equation is going to be true or false
				if(true_false == 1){
					flag = 1;
				}else {
					flag = 0;
				}

			//Generate operands & operators for the equation.
				val1 = rand() % 21;
				val2 = rand() % 10;
				int operation =1;

				//Create the equation & Display it on the screen
					if(operation == 1){
						if(flag == 1){
							res = val1+val2;
						 }else{
							res = rand( ) % 31;
						 }

						 	sprintf(screen_disp, " %d + %d  =  %d", val1, val2, res);
						 	RIT128x96x4StringDraw(screen_disp, 24, 16, 15);
						 	vTaskDelay(15000);



						 //
						 //
						 //
						 //
						 //
						 //			Joystick Code!
						 //
						 //
						 //
						 //
						 //
					 }else if(operation == 2){
						if(flag == 1){
							res = val1-val2;
						 }else{
							res = rand( ) % 11;
						 }
						 	//sprintf("%d - %d = %d", val1, val2, res);
						 			 //
						 //
						 //
						 //
						 //
						 //			Joystick Code!
						 //
						 //
						 //
						 //
						 //
					 }else{
						if(flag == 1){
							res = val1*val2;
						 }else{
							res = rand( ) % 201;
						 }
						 	//sprintf("%d x %d = %d", val1, val2, res);
						 			 //
						 //
						 //
						 //
						 //
						 //			Joystick Code!
						 //
						 //
						 //
						 //
						 //
					 }


	}
 }
 //*****************************************************************************
 //
 //	Main
 //
 //*****************************************************************************
 int main(void) {

	 BlinkInit();
	 while(1){

		 BlinkExecute();
	 }

	/*
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);
 	//
 	//	Create a task to blink LED
 	//
 	xTaskCreate(BlinkLED, (signed portCHAR*) "Blinky", 32, NULL, 1, NULL);
 	//
 	//	Create a task to read the joystick
 	//
 	xTaskCreate(game, (signed portCHAR*) "Joystick", 512, NULL, 1, NULL);
 	PrintInit();
 	//
 	//	Start FreeRTOS Task Scheduler
 	//
 	vTaskStartScheduler();
 	while(1){}
 	*/
 }
