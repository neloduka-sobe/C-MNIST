#include "nn.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

/*
* Return random double between -1 and 1
* Returns: Random double between -1 and 1
*/
double rand_double() {
    return (double)rand() / RAND_MAX * 2.0 - 1.0;
}

/*
* Create a neuron
* Takes: nin - number of inputs, nonlin - true if non-lineary
* Returns: Pointer to a Neuron
*/
Neuron* create_neuron(int nin, bool nonlin) {
    return;
}

/*
* Call a Neuron
* Takes: Pointer to a neuron, pointer to a value to be put into the neuron
* Returns: Value with the evaluated neuron
*/
Value call_neuron(Neuron *neuron, Value *x) {
    return;
}

/*
* Get neuron parameters
* Takes: Pointer to a neuron, number of parameters in a neuron
* Returns: Pointer to parameters of Neuron
*/
Value* neuron_parameters(Neuron *neuron, int *param_size) {
    return;
}

/*
* Creates a leyer
* Takes: nin - number of inputs, nout - number of outputs, nonlin - if nonlinear
* Returns: Pointer to a layer
*/
Layer* create_layer(int nin, int nout, bool nonlin) {
    return;
}

/*
* Call the layer
* Takes: Layer pointer, value for which to evaluate, size of the input
* Returns: Value returned by evaluation of the layer
*/
Value call_layer(Layer *layer, Value *x, int x_size) {
    return;
}

/*
* Returns layer parameters
* Takes: Pointer to a layer, pointer to number of the parameters
* Returns: Pointer to parameters of a layer
*/
Value* layer_parameters(Layer *layer, int *param_size) {
    return;
}

/*
* Creates the MLP
* Takes: Number of inputs, array of outputs, number of layers
* Returns: Pointer to MLP object
*/
MLP* create_MLP(int nin, int *nouts, int n_layers) {
    return;
}

/*
* Calls the MLP
* Takes: Pointer to te MLP, Value for which to evaluate, and size of the input
* Returns: Value for the MLP evaluated for x
*/
Value call_MLP(MLP *mlp, Value *x, int x_size) {
    return;
}

/*
* Returns MLP parameters
* Takes: pointer to the mlp, pointer to array of sizes of parameters
* Returns: Values of the parameters of MLP
*/
Value* MLP_parameters(MLP *mlp, int *param_size) {
    return;
}
