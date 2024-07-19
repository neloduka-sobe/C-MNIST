#include "engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
//#include <gsl/gsl_matrix.h>
//#include <gsl/gsl_blas.h>

/* * Initialize the value
* Takes: data to be stored in the node, pointer to the linked list of children
* Returns: pointer to the value
*/
Value* create_value(double data, ValueNode* children) {
    Value* v = (Value *) calloc(sizeof(Value), 1);
    assert(v);
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
    assert(node);
    node->value = child;
    node->next = head;
    return node;
}
/*
* Check is value in a linked list
* Takes: pointer to a linked list, pointer to value
* Returns: 1 if value in linked list, 0 otherwise
*/
int in_linked_list(ValueNode* head, Value* v) {
    ValueNode* p = head;
    while (p != NULL) {
        if (p->value == v) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

/*
* Add two values: a and b
* Takes: values a,b != NULL
* Returns: pointer to a new value being the sum of a and b
*/
Value* add(Value* a, Value* b) {
    assert(a);
    assert(b);

    ValueNode* children = NULL;
    children = add_child(children, a);
    children = add_child(children, b);
    Value* ret = create_value(a->data + b->data, children);
    ret->backward = add_backward;
    return ret;
}

/*
* Multiply two values: a and b
* Takes: values a,b != NULL
* Returns: pointer to a new value being the product of a and b
*/
Value* mul(Value* a, Value* b) {
    assert(a);
    assert(b);

    ValueNode* children = NULL;
    children = add_child(children, a);
    children = add_child(children, b);
    Value* ret = create_value(a->data * b->data, children);
    ret->backward = mul_backward;
    return ret;
}

/*
* Take value to the power of exponent
* Takes: value a != NULL
* Returns: pointer to a new value being equal to a^double
*/
Value* power(Value* a, double exponent) {
    assert(a);

    ValueNode* children = NULL;
    children = add_child(children, a);
    Value* e = create_value(exponent, NULL);
    children = add_child(children, e);
    Value* ret = create_value(pow(a->data, exponent), children);
    ret->backward = power_backward;
    return ret;
}

/*
* Calculate ReLU of the value
* Takes: value a != NULL
* Returns: pointer to a new value being equal to input with ReLU applied
*/
Value* relu(Value* a) {
    ValueNode* children = NULL;
    children = add_child(children, a);

    Value* ret = NULL;
    if (a->data < 0) {
       ret = create_value(0, children);
    }
    else {
       ret = create_value(a->data, children);

    }
    return ret;
}

/*
* Calculate tanh of the value
* Takes: value a != NULL
* Returns: pointer to a new value being equal to input with tanh applied
*/
Value* tangenth(Value* a) {
    assert(a);

    ValueNode* children = NULL;
    children = add_child(children, a);
    double x = a->data;
    double t = tanh(x); //((exp(2+x)-1)/(exp(2+x)+1));
    Value* ret = create_value(t, children);
    ret->backward = tangenth_backward;
    return ret;
}

/*
* Calculate softmax of the value
* Takes: value a != NULL
* Returns: pointer to a new value being equal to input with softmax applied
Value* softmax(Value* a) {
    // TODO
    return;
}
*/

/*
* Calculate logarithm of the value
* Takes: value a != NULL
* Returns: pointer to a new value being equal to input with logarithm applied
Value* logarithm(Value* a) {
    // TODO
    return;
}
*/

/*
* Calculate backward prop for the value
* Takes: pointer to a value
*/
void backward(Value* this) {
    assert(this);

    ValueNode* topo = NULL;
    ValueNode* visited = NULL;

    build_topo(this, &topo, &visited);

    this->grad = 1.0;

    ValueNode* p = topo;
    while (p != NULL) {
        if (p->value->backward != NULL) {
            p->value->backward(p->value);
        }
        p = p->next;
    }

    free_value_node(topo);
    free_value_node(visited);
    return;
}

/*
* Populate the linked list with pointers n topological order
* Takes: value v, to calculate, linked list of pointers in topological order, linked list of visited nodes pointers
*/
void build_topo(Value* v, ValueNode** topo, ValueNode** visited) {
    if (in_linked_list(*visited, v)) {
        return;
    }

    *visited = add_child(*visited, v);

    ValueNode* p = v->children;
    while (p != NULL) {
        build_topo(p->value, topo, visited);
        p = p->next;
    }

    *topo = add_child(*topo, v);

    return;
}

/*
* Back propagation for addition
* Takes: Value
*/
void add_backward(Value* this) {
    assert(this);
    // We are sure from implementation that there are two children
    this->children->value->grad += this->grad;
    this->children->next->value->grad += this->grad;
    return;
}

/*
* Back propagation for multiplication
* Takes: Value
*/
void mul_backward(Value* this) {
    assert(this);
    // We are sure from implementation that there are two children
    this->children->value->grad += this->children->next->value->data * this->grad;
    this->children->next->value->grad += this->children->value->data * this->grad;
    return;
}

/*
* Back propagation for exponentiation
* Takes: Value
*/
void power_backward(Value* this) {
    assert(this);
    double exponent = this->children->next->value->data;
    this->children->value->grad += (exponent * pow(this->children->value->data, exponent - 1)) * this->grad;
    return;
}

/*
* Back propagation for ReLU
* Takes: Value
*/
void relu_backward(Value* this) {
    assert(this);
    this->children->value->grad += (this->data > 0) * this->grad;
    return;
}

/*
* Back propagation for tanh
* Takes: Value
*/
void tangenth_backward(Value* this) {
    assert(this);
    this->children->value->grad += (1-pow(this->data, 2)) * this->grad;
    return;
}

/*
* Back propagation for softmax
* Takes: Value
void softmax_backward(Value* this) {
    // TODO
    return;
}
*/

/*
* Back propagation for logarithm
* Takes: Value
void logarithm_backward(Value* this) {
    // TODO
    return;
}
*/

/*
* Prints the value
* Takes: pointer to the value
*/
void print_value(Value* v) {
    assert(v);
    printf("Data: %f\n", v->data);
    printf("Grad: %f\n", v->grad);
    printf("Children:");
    ValueNode* p = v->children; 
    while (p != NULL) {
        print_value(p->value);
        p = p->next;
    }
    return;
}


/*
* Free the Value structure
* Takes: Pointer to the Value
*/
void free_value(Value* v) {
    assert(v);

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
    assert(node);
    free_value(node->value);
    ValueNode* ret = node->next;
    free(node);
    return ret;
}
