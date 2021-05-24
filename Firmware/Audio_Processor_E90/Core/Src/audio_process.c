/*
 * audio_process.c
 *
 *  Created on: Apr 16, 2021
 *      Author: skylercornell
 */


#include "audio_process.h"
#include "biquads.h"
#include "CONSTANTS.h"
#include <math.h>
#include <stdint.h>


/*
 * Declare global variables and structures units here
 */

// Bandpass
biquad_t LPF_biquad;

float F0;
float Fs = (float)SAMPLE_RATE_ACTUAL;
float w0;
float Q;

float in, out;

extern uint32_t pot_vals[3];

/*
 * Executes once before entering program loop
 */

void process_init()
{
  //reset biquad history
  LPF_biquad.yn2 = 0;
  LPF_biquad.yn1 = 0;
  LPF_biquad.xn2 = 0;
  LPF_biquad.xn1 = 0;


  F0 = 400; // start off at 1000 Hz center freq;
  w0 = 2*3.141592*(F0/Fs);
  Q = 1;

  //compute an initial set of coefficients to avoid Nan
  compute_LPF_coeff(&LPF_biquad, w0, Q);

}

void loop() {

   //handle LEDs and Pots on slower time scale
}

void process(int *in_sample, int *out_sample)
{

  in = (float)*in_sample;

  //produce filtered output sample
  compute_biquad(&LPF_biquad, &in, &out);

  //cast float to int
  *out_sample = (int)out;
  //*out_sample = *out_sample>>1;
  //*out_sample = *in_sample;
}


