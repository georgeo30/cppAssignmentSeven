#ifndef _PERCEPTRON_H
#define _PERCEPTRON_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
 
namespace THNGEO002
{

    class Perceptron
    {
        private:
            double w1;  //input 1 weight
            double w2;  //input 2 weight
            const double lr=0.1;    //learning rate
            double bias=0.2; //bias
            const int threshold=0;   //threhold
            std::vector<int> targetOutputs; //vector to hold the target putputs
            std::vector<int> inputOne;  //vector to hold the input one
            std::vector<int> inputTwo; //vector to hold input two
            bool converge=false;
            std::vector<int> calcOutputs;
        public:
            Perceptron(double w1,double w2,std::vector<int> const &target,std::vector<int> const &in1,std::vector<int> const &in2);
            ~Perceptron();
            void train(); //trainin the perceptron
            double calcPerceptronOutput(int inOne,int inTwo); //method to calculate the perceptron output using the weights
            double deltaWeight(int calcOutput,int x,int t);   //method to calculate the delta value
            bool convergenceCheck();
            int thresholdCheck(double v);
            void test();

    };
    
}
#endif