/*
 * biquads.h
 *
 *  Created on: May 20, 2021
 *      Author: skylercornell
 */

#ifndef INC_BIQUADS_H_
#define INC_BIQUADS_H_



#endif /* INC_BIQUADS_H_ */

typedef struct {

  float xn1, xn2;  //previous inputs
  float yn1,yn2;  //prev outputs

  //coefficients
  float b0,b1,b2,a0,a1,a2;

}biquad_t;

void compute_BPF_coeff(biquad_t *bq, float w0, float Q);
void compute_LPF_coeff(biquad_t *bq, float w0, float Q);

void compute_biquad(biquad_t *bq, float *in, float *out);
