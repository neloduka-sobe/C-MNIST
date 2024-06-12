#include "engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>


Value* create_value(double data, ValueNode* children, char* op) {
    return;
}

ValueNode* add_child(ValueNode* head, Value* child) {
    return;
}

Value* add(Value* a, Value* b) {
    return;
}

Value* mul(Value* a, Value* b) {
    return; 
}

Value* pow_val(Value* a, double exponent) {
    return;
}

Value* relu(Value* a) {
    return;
}

void backward(Value* this) {
    return;
}

void build_topo(Value* v, Value** topo, int* topo_size, int* visited, int* visited_size) {
    return;
}

void add_backward(Value* this) {
    return;
}

void mul_backward(Value* this) {
    return;
}

void pow_backward(Value* this) {
    return;
}

void relu_backward(Value* this) {
    return;
}

void print_value(Value* v) {
    return;
}

void free_value(Value* v) {
    return;
}

ValueNode* free_value_node(ValueNode* node) {
    assert(node != NULL);
    free_Value(node->value);
    ValueNode* ret = node->next;
    free(node);
    return ret;
}
