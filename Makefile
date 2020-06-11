CC=g++
LIB=-std=c++11
create: Perceptron.h Perceptron.cpp Neuron.h Neuron.cpp driver.cpp
	$(CC) $(LIB) Perceptron.h Perceptron.cpp Neuron.h Neuron.cpp driver.cpp -c
	$(CC) $(LIB) driver.o Perceptron.o Neuron.o -o percept
	./percept

 

clean:
	rm Neuron.o
	rm Perceptron.o
	rm driver.o
	rm Neuron.h.gch
	rm Perceptron.h.gch
	rm percept
