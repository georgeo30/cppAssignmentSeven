#include "Perceptron.h"
namespace THNGEO002{
    Perceptron::Perceptron(double w1,double w2,std::vector<int> const &target,std::vector<int> const &in1,std::vector<int> const &in2):w1(w1),w2(w2))
    {
        targetOutputs=target;
        inputOne=in1;
        inputTwo=in2;
    }
}