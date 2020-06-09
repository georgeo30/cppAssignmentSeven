#include "Perceptron.h"
namespace THNGEO002{
    Perceptron::Perceptron(double w1,double w2,std::vector<int> const &target,std::vector<int> const &in1,std::vector<int> const &in2):w1(w1),w2(w2)
    {
        targetOutputs=target;
        inputOne=in1;
        inputTwo=in2;
        
    }
    Perceptron::~Perceptron(){

    }
    void Perceptron::train(){
        for (int i = 0; i < targetOutputs.size(); i++)
        {
            int output;
            double v=calcPerceptronOutput(i);
            //std::cout<<v<<std::endl;
            if (v<=threshold)
            {
                //std::cout<<0<<std::endl;
                output=0;
            }
            else{
                //std::cout<<1<<std::endl;
                output=1;
            }
            double deltaW1=deltaWeight(output,inputOne[i],targetOutputs[i]);
            double deltaW2=deltaWeight(output,inputTwo[i],targetOutputs[i]);
            w1+=deltaW1;
            w2+=deltaW2;
            std::cout<<inputOne[i]<<"  "<<inputTwo[i]<<"  "<<targetOutputs[i]<<"  "<<output<<"  "<<targetOutputs[i]-output<<"  "<<w1<<"  "<<w2<<std::endl;
            
            
        }
        
    }
    double Perceptron::calcPerceptronOutput(int xIndex){
       return (w1*inputOne[xIndex])+(w2*inputTwo[xIndex])-bias;
    }
    double Perceptron::deltaWeight(int calcOutput,int x,int t){
        return lr*(t-calcOutput)*x;

    }
    void Perceptron::test(){
        for (int i = 0; i < targetOutputs.size(); i++)
        {
            std::cout<<inputOne[i]<<std::endl;

        }
        
    }

}