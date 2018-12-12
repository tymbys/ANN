#include <cstdlib>
#include <iomanip>
#include <vector>
#include <unistd.h>
#include "neuralNet.h"
#include "MNIST.h"
#include "NN_W.h"

using namespace std;
//http://www.pvsm.ru/net/7339/print/
//https://neuronus.com/theory/nn/955-nejronnye-seti-kokhonena.html

MNIST mnist;

neuralNet *neural_net;

void neuralNet_TEST();

int main(int argc, char** argv) {

    //Kohonen();

    //MNIST_TEST();
    neuralNet_TEST();

    return 0;
}


void neuralNet_TEST() {

    const int count_data_train = 10; //количество выборок кажной цифры для тренировки
    int inc_train[count_data_train] = {0};
    neural_net = new neuralNet(28 * 28, 10, 10);

    //sleep(3);

    const int count = 5000;
    vector<vector<double>> ar_img;
    vector<vector<double>> ar_label;
    mnist.ReadMNIST("./db/t10k-images.idx3-ubyte", count, 784, ar_img, IS_IMG); //28x28
    mnist.ReadMNIST("./db/t10k-labels.idx1-ubyte", count, 1, ar_label, IS_LABEL);


    int i = 0, i_datda_train = 0;

    for (vector<double> img : ar_img) {
        int w = 28, h = 28;
        int x = 0, y = 0;

        int label = ar_label[i][0];

        if (label >= 0 && label < 10) { //0..9

                for(int im_ind=0; im_ind< 784; im_ind++){
                   neural_net->tests[label].image[im_ind] =  img[im_ind] > 100 ? 1 : 0;
                }

                for (int j = 0; j < 10; j++) {
                    if (j == label)
                        neural_net->tests[label].output[j] = 1;
                    else
                        neural_net->tests[label].output[j] = 0;
                }

                //data_train.label[i_datda_train] = label;
                //data_train.data[i_datda_train] = img;
                i_datda_train++;
            }

            cout << "Count image: " << i_datda_train << endl;


    }


    //exit(0);


    int test;
    double mse, noise_prob;


//vector <vector<double>> whi, woh;

neural_net->init_network((const double *)&w_h_i[0][0], (const double *)&w_o_h[0][0]);

    noise_prob = 0;
    int guess, ans;
    for (i = 0; i < 10; i++) {
        test = neural_net->rand_test();
        neural_net->set_network_inputs(test, noise_prob);

        neural_net->feed_forward();



        guess = neural_net->classifier() + '0';
        ans = neural_net->find_ans(test) + '0';
        printf("\nclassified as %c, supposed to be %c\n", guess, ans);
        //*
        for (int j = 0; j < neural_net->INPUT_NEURONS; j++) {
            if ((j % 28) == 0) printf("\n");
            //printf("%d ", (int) neural_net->inputs[j]);
            cout << setw(4) << (int) neural_net->inputs[j];
        } //*/
        //noise_prob += 0.05;

    }
    
    neural_net->saveNetAsInclude("../ANN_Small/NN_W");

    printf("w_h_i[0][0]: %f\n",neural_net->w_h_i[5][500]);
}
