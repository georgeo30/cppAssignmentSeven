#ifndef _Neuron_H
#define _Neuron_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
namespace THNGEO002
{

    class Neuron
    {
        private:
            double w1;  //input 1 weight
            double w2;  //input 2 weight
            double w3;  //input 2 weight
            const double lr=0.1;    //learning rate
            double bias; //bias
            double inputOne;  //vector to hold the input one
            double inputTwo; //vector to hold input two
            double inputThree; //vector to hold input two
            std::vector<double > inputs;
            std::vector<double > weights;
            
        public:
            Neuron(std::vector<double > in,std::vector<double > weight,double bias);
            ~Neuron();
            double calcNeuronOutput(); //method to calculate the Neuron output using the weights

            double thresholdCheck(double v);
            void test();

    };
    
}
#endif