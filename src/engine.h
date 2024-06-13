#ifndef ENGINE_H
#define ENGINE_H

// Structure definition
typedef struct Value {
    double data;
    double grad;
    struct ValueNode* children; // Linked list of children
    void (*backward)(struct Value* this);
} Value;

typedef struct ValueNode {
    Value* value;
    ValueNode* next;
} ValueNode;


// Function declarations

// Operations on structure
Value* create_value(double data, ValueNode* children);
ValueNode* add_child(ValueNode* head, Value* child);

// Operation on two structures in forward pass
Value* add(Value* a, Value* b);
Value* mul(Value* a, Value* b);
Value* pow(Value* a, double exponent);
Value* relu(Value* a);
Value* tanh(Value* a);
Value* softmax(Value* a);
Value* log(Value* a);
Value* matrix_mul(Value* a);
Value* reduce_sum(Value* a;

// Operations for backward pass
void backward(Value* this);
void build_topo(Value* v, Value** topo, int* topo_size, int* visited, int* visited_size);
void add_backward(Value* this);
void mul_backward(Value* this);
void pow_backward(Value* this);
void relu_backward(Value* this);
void tanh_backward(Value* this;
void softmax_backward(Value* this);
void log_backward(Value* this);
void matrix_mul_backward(Value* this));
void reduce_sum_backward(Value* this);

void print_value(Value* v);
void free_value(Value* v);
ValueNode* free_value_node(ValueNode* node);

#endif
