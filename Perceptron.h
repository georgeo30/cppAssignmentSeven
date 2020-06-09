#ifndef _PERCEPTRON_H
#define _PERCEPTRON_H
#include <string>
#include <vector>
namespace THNGEO002
{

    class Perceptron
    {
        private:
            double w1;  //input 1 weight
            double w2;  //input 2 weight
            const double lr;    //learning rate
            const double threshold; //threshold
            std::vector<int> &targetOutputs; //vector to hold the target putputs
            std::vector<int> &inputOne;  //vector to hold the input one
            std::vector<int> &inputTwo; //vector to hold input two
        public:
            Perceptron(double w1,double w2,std::vector<int> const &target,std::vector<int> const &in1,std::vector<int> const &in2);


    }
    
}
#endif