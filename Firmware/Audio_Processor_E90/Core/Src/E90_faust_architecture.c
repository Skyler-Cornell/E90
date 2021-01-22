
/*
 * STM32AudioDSP Faust Architecture File
 * Faust command line tool generates a c file valid for this project's audio
 * framework.
 * Use the following command to generate the code:
 * faust -a E90_faust_architecture.c -lang c -o generated_audio_process.c my_faust_fx.dsp
 * The generated c file should replace audio_process.c for faust effect to run
 */

#include "audio_process.h"
#include "CONSTANTS.h"

<<includeIntrinsic>>

<<includeclass>>

/*
 * global faust object pointers
 */
mydsp* dsp;
FAUSTFLOAT** inputs;
FAUSTFLOAT** outputs;

void process_init() {

  // allocate memory for dsp struct
  dsp = (mydsp*)malloc(sizeof(mydsp));

}

// assumes a right justified 24 bit signed sample
void process(int *left_in, int *right_in, int *left_out, int *right_out) {


  inputs[0] = left_in; //inputs[0] gets pointer to left sample
  inputs[1] = right_in; //inputs[1] gets pointer to right sample

  computemydsp(dsp, 1, inputs, outputs)

  *right_out = *outputs[1]; //dereference pointer to right_out and set to the dereferenced pointer output[0]
  *left_out = *outputs[0];

}
