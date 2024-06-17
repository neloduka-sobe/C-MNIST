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
    assert(nin > 0);
    Neuron* neuron = (Neuron*) calloc(sizeof(Neuron), 1);
    assert(neuron);
    neuron->w = NULL;
    for (int i = 0; i < nin; i++) {
        Value* v = create_value(rand_double(), NULL);
        neuron->w = add_child(neuron->w, v);
    }

    neuron->b = create_value(0.0, NULL);
    neuron->nonlin = nonlin;
    neuron->nin = nin;
    return neuron;
}

/*
* Call a Neuron
* Takes: Pointer to a neuron, pointer to a value to be put into the neuron
* Returns: Value with the evaluated neuron
*/
Value call_neuron(Neuron* neuron, ValueNode* x) {
    // TODO check 
    Value* act = neuron->b;
    ValueNode* w_node = neuron->w;

    for (int i = 0; i < neuron->nin; i++) {
        act = add(act, mul(w_node->value, x->value->data));
        w_node = w_node->next;
        x = x->next;
    }
    if (neuron->nonlin) {
        return *relu(act);
    } else {
        return *act;
    }
}

/*
* Get neuron parameters
* Takes: Pointer to a neuron, number of parameters in a neuron
* Returns: Pointer to parameters of Neuron
*/
ValueNode* neuron_parameters(Neuron *neuron, int *param_size) {
    return;
}

/*
* Creates a leyer
* Takes: nin - number of inputs, nout - number of outputs, nonlin - if nonlinear
* Returns: Pointer to a layer
*/
Layer* create_layer(int nin, int nout, bool nonlin) {
    Layer* layer (Layer*) calloc(sizeof(Layer), 1);
    assert(layer);
    layer->neurons = NULL;
    for (int i = 0; i < nout; i++) {
        Neuron* neuron = create_neuron(nin, nonlin);
        NeuronNode* neuron_node = (NeuronNode*) calloc(sizeof(NeuronNode), 1);
        assert(neuron_node);
        neuron_node->value = neuron;
        neuron_node->next = layer->neurons;
        layer->neurons = neuron_node;

    }
    layer->nout = nout;

    return layer;
}

/*
* Call the layer
* Takes: Layer pointer, value for which to evaluate, size of the input
* Returns: Value returned by evaluation of the layer
*/
Value call_layer(Layer *layer, ValueNode *x, int x_size) {
    return;
}

/*
* Returns layer parameters
* Takes: Pointer to a layer, pointer to number of the parameters
* Returns: Pointer to parameters of a layer
*/
ValueNode* layer_parameters(Layer *layer, int *param_size) {
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
Value call_MLP(MLP *mlp, ValueNode *x, int x_size) {
    return;
}

/*
* Returns MLP parameters
* Takes: pointer to the mlp, pointer to array of sizes of parameters
* Returns: Values of the parameters of MLP
*/
ValueNode* MLP_parameters(MLP *mlp, int *param_size) {
    return;
}
