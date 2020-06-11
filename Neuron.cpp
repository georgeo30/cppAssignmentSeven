#include "Neuron.h"
namespace THNGEO002{
    Neuron::Neuron(std::vector<double > in,std::vector<double > weight,double bias):bias(bias)
    {
        
        inputs=in;
        weights=weight;
        
    }
    Neuron::~Neuron(){

    }
    
    double Neuron::calcNeuronOutput(){
        double v=0;
        for (int i = 0; i < inputs.size(); i++)
        {
            v+=(inputs[i]*weights[i]);
        }
        
      v+=bias;
       return thresholdCheck(v);
    }


    double Neuron::thresholdCheck(double v){
        double val;
        val=1/(1+exp(-v));
        return val;
    }


}