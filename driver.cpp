#include "Perceptron.h"
#include <string>
#include "Neuron.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib> 
#include <ctime> 
int main(int argc, char *argv[])
{srand( (unsigned)time( NULL ) );
    std::cout<<"PART 1"<<std::endl<<std::endl;
    std::cout<<"Training AND gate... "<<std::endl;
    std::vector<int> tAND={0,0,0,1};
    std::vector<int> in1={0,0,1,1};
    std::vector<int> in2={0,1,0,1};
    THNGEO002::Perceptron perceptAnd((double) rand()/RAND_MAX,(double) rand()/RAND_MAX,tAND,in1,in2);
    perceptAnd.train();
    std::cout<<"Training OR gate... "<<std::endl;
    std::vector<int> tOR={0,1,1,1};
    THNGEO002::Perceptron perceptOr((double) rand()/RAND_MAX,(double) rand()/RAND_MAX,tOR,in1,in2);
    perceptOr.train();
    std::cout<<"Training NAND gate..."<<std::endl;
    std::vector<int> tNAND={1,1,1,0};
    THNGEO002::Perceptron perceptNand((double) rand()/RAND_MAX,(double) rand()/RAND_MAX,tNAND,in1,in2);
    perceptNand.train();
  std::cout<<std::endl;
  std::cout<<"XOR = AND(NAND,OR)"<<std::endl<<std::endl;
  const char separator    = ' ';
            const int nameWidth     = 6;
            const int numWidth      = 8;
            std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "X";
        std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Y";
        std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Output";
        std::cout<<std::endl;
    for (int i = 0; i < in1.size(); i++)
    {
        std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << in1[i];
        std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << in2[i];

        std::cout<< std::left << std::setw(nameWidth) << std::setfill(separator)<<perceptAnd.thresholdCheck(perceptAnd.calcPerceptronOutput(perceptNand.thresholdCheck(perceptNand.calcPerceptronOutput(in1[i],in2[i])),perceptOr.thresholdCheck(perceptOr.calcPerceptronOutput(in1[i],in2[i]))))<<std::endl;
        
    }
    

        std::cout<<std::endl<<"PART 2"<<std::endl<<std::endl;



    std::vector<double> outputHiddenOne;
    std::vector<double> inputs1={1.30,2.70,0.8};
    std::vector<double> weightn1={0.1,0.2,0.5};
    THNGEO002::Neuron n1(inputs1,weightn1,0.1);
    std::vector<double> weightn2={-0.4,1.0,-0.6};
    THNGEO002::Neuron n2(inputs1,weightn2,-0.3);
    outputHiddenOne.push_back(n1.calcNeuronOutput());
    outputHiddenOne.push_back(n2.calcNeuronOutput());
    std::vector<double> weightn3={0.8,1.0};
    THNGEO002::Neuron n3(outputHiddenOne,weightn3,-0.3);
    for (int i = 0; i < outputHiddenOne.size(); i++)
    {
        std::cout<<"Output of hidden neuron "<<i+1<<" : "<<outputHiddenOne[i]<<std::endl;
    }
    double n3Out=n3.calcNeuronOutput();
    std::cout<<"Final output Neuron: "<<n3Out<<std::endl;
    int power=2;
    std::cout<<"Mean Squared Average: "<<pow(n3Out-0.36,power)<<std::endl;

        
    

}