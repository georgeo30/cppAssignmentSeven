#include "Perceptron.h"
#include <string>
#include <iostream>
int main(int argc, char *argv[])
{
    std::cout<<"AND GATE Training"<<std::endl;
    std::vector<int> t={0,0,0,1};
    std::vector<int> in1={0,0,1,1};
    std::vector<int> in2={0,1,0,1};
    THNGEO002::Perceptron perceptAnd(0.3,0.1,t,in1,in2);
    perceptAnd.train();
    std::cout<<"OR GATE Training"<<std::endl;
    std::vector<int> t1={0,1,1,1};
    std::vector<int> in11={0,0,1,1};
    std::vector<int> in21={0,1,0,1};
    THNGEO002::Perceptron perceptOr(0.3,0.1,t1,in11,in21);
    perceptOr.train();
    
    // std::cout<<"NOT GATE Training"<<std::endl;
    // std::vector<int> t11={1,0};
    // std::vector<int> in111={0,1};
    // THNGEO002::PerceptronNot perceptNo(0.3,t11,in111);
    // perceptNo.train();
    std::cout<<"NAND GATE Training"<<std::endl;
    std::vector<int> t111={1,1,1,0};
    std::vector<int> in1111={0,0,1,1};
    std::vector<int> in2111={0,1,0,1};
    THNGEO002::Perceptron perceptNor(0.3,0.1,t111,in1111,in2111);
    perceptNor.train();
  
        

}