#ifndef NN_W_H
#define NN_W_H
//#define INPUT_NEURONS 784
//#define HIDDEN_NEURONS 10
//#define OUTPUT_NEURONS 10
const int INPUT_NEURONS =784;
const int HIDDEN_NEURONS =10;
const int OUTPUT_NEURONS =10;

//extern const double w_h_i[10][INPUT_NEURONS + 1];
//extern const double w_o_h[10][HIDDEN_NEURONS + 1];

extern const double w_h_i[10][785];
extern const double w_o_h[10][11];
#endif
