#include "Perceptron.h"
namespace THNGEO002{
    Perceptron::Perceptron(double w1,double w2,std::vector<int> const &target,std::vector<int> const &in1,std::vector<int> const &in2):w1(w1),w2(w2)
    {
        targetOutputs=target;
        inputOne=in1;
        inputTwo=in2;
        for (int i = 0; i < targetOutputs.size(); i++)
        {
            calcOutputs.push_back(-1);
        }
        
    }
    Perceptron::~Perceptron(){

    }
    void Perceptron::train(){
        while(convergenceCheck()==false)
        {
            // /* code */
            const char separator    = ' ';
            const int nameWidth     = 23;
            const int numWidth      = 8;
            // std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "x1";
            // std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "x2";
            // std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Expected output";
            // std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Calculated Output";
            // std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Expected - calculated";
            // std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "w1";
            // std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "w2";
            // std::cout<<std::endl;
        for (int i = 0; i < targetOutputs.size(); i++)
        {
            int output=-1;
            double v=calcPerceptronOutput(inputOne[i],inputTwo[i]);
            //std::cout<<v<<std::endl;
            output=thresholdCheck(v);
            calcOutputs[i]=output;
            double deltaW1=deltaWeight(output,inputOne[i],targetOutputs[i]);
            double deltaW2=deltaWeight(output,inputTwo[i],targetOutputs[i]);
            w1+=deltaW1;
            w2+=deltaW2;
            bias+=lr*(targetOutputs[i]-output);
            const char separator    = ' ';
            const int nameWidth     =23;
            const int numWidth      = 8;
            // std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << inputOne[i];
            // std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << inputTwo[i];
            // std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << targetOutputs[i];
            // std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << output;
            // std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << targetOutputs[i]-output;
            // std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << w1;
            // std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << w2;
            // //std::cout<<inputOne[i]<<"  "<<inputTwo[i]<<"  "<<targetOutputs[i]<<"  "<<output<<"  "<<targetOutputs[i]-output<<"  "<<w1<<"  "<<w2<<std::endl;
            // std::cout<<std::endl;
            
            
            
        }
        //std::cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
        }
        
    }
    double Perceptron::calcPerceptronOutput(int inOne,int inTwo){
       return (w1*inOne)+(w2*inTwo)+bias;
    }
    double Perceptron::deltaWeight(int calcOutput,int x,int t){
        return lr*(t-calcOutput)*x;

    }
    bool Perceptron::convergenceCheck(){
        for (int i = 0; i < calcOutputs.size(); i++)
        {
            if(calcOutputs[i]!=targetOutputs[i]){
                return false;
            }
        }
        return true;
        
    }
    int Perceptron::thresholdCheck(double v){
        if(v>=threshold){
            return 1;
        }
        return 0;
    }
    void Perceptron::test(){
        for (int i = 0; i < targetOutputs.size(); i++)
        {
            std::cout<<inputOne[i]<<std::endl;

        }
        
    }

}