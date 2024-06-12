#include "engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

/*
* Initialize the value
* Takes: data to be stored in the node, pointer to the linked list of children
* Returns: pointer to the value
*/
Value* create_value(double data, ValueNode* children) {
    Value* v = (Value *) calloc(sizeof(Value), 1);
    v->data = data;
    v->grad = 0;
    v->children = children;
    v->backward = NULL;
    return v;
}

/*
* Add child to the linked list of children
* Takes: head of the linked list, pointer to the child to be added
* Returns: pointer to new head of the linked list
*/
ValueNode* add_child(ValueNode* head, Value* child) {
    ValueNode* node = (ValueNode*) calloc(sizeof(ValueNode), 1);
    node->value = child;
    node->next = head;
    return node;
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

/*
* Free the Value structure
* Takes: Pointer to the Value
*/
void free_value(Value* v) {
    assert(v != NULL);

    // Free linked list
    ValueNode *p = v->children;
    while (p != NULL) {
        free_value_node(p);
    }
    free(v);
    return;
}

/*
* Free the ValueNode on adress at node
* Takes: pointer to the ValueNode
* Returns: pointer to the next node if exists, else NULL.
*/
ValueNode* free_value_node(ValueNode* node) {
    assert(node != NULL);
    free_value(node->value);
    ValueNode* ret = node->next;
    free(node);
    return ret;
}
