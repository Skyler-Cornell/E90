/*
 * audio_process.c
 *
 *  Created on: Jan 22, 2020
 *      Author: skylercornell
 */

#include "audio_process.h"

#include <math.h>

/*
 * Declare global variables and structures units here
 */


/*
 * Executes once before entering program loop
 */
void process_init()
{


}

/*
 * Main DSP routine, CPU enters function once per sample period
 * samples are right justified 24 bit signed
 */
void process(int *left_in, int *right_in, int *left_out, int *right_out)
{
     HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);

     *right_out = *right_in;
     *left_out = *left_in;

}

