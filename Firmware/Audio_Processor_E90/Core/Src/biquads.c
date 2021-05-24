/*
 * biquads.c
 *
 *  Created on: May 20, 2021
 *      Author: skylercornell
 */

#include "biquads.h"
#include <math.h>
#include <stdint.h>

void compute_LPF_coeff(biquad_t *bq, float w0, float Q){

  float one_minus_cosw0 = 1-cos(w0);
  float alpha = sin(w0)/(2*Q);

  bq->b0 = one_minus_cosw0/2;
  bq->b1 = one_minus_cosw0;
  bq->b2 = one_minus_cosw0/2;

  bq->a0 = 1+alpha;
  bq->a1 = -2*cos(w0);
  bq->a2 = 1-alpha;

}

void compute_BPF_coeff(biquad_t *bq, float w0, float Q){
  float sinw0_over2 = sin(w0)/2;
  float alpha = sinw0_over2/Q;;

  bq->b0 = sinw0_over2;
  bq->b1 = 0;
  bq->b2 = -sinw0_over2;

  bq->a0 = 1+alpha;
  bq->a1 = -2*cos(w0);
  bq->a2 = 1-alpha;

}


void compute_biquad(biquad_t *bq, float *in, float *out){


  float b0 = bq->b0;
  float b1 = bq->b1;
  float b2 = bq->b2;

  float a0 = bq->a0;
  float a1 = bq->a1;
  float a2 = bq->a2;

  // Direct Form 1 Biquad Implementation
  *out = (*in)*(b0/a0);
  *out += bq->xn1*(b1/a0);
  *out += bq->xn2*(b2/a0);
  *out -= bq->yn1*(a1/a0);
  *out -= bq->yn2*(a2/a0);

  //update biquad history
  bq->yn2 = bq->yn1;
  bq->yn1 = *out;
  bq->xn2 = bq->xn1;
  bq->xn1 = *in;
}
