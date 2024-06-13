#ifndef ENGINE_H
#define ENGINE_H

typedef struct ValueNode ValueNode;
typedef struct Value Value;

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

// Operations on structures
Value* create_value(double data, ValueNode* children);
ValueNode* add_child(ValueNode* head, Value* child);
void print_value(Value* v);
void free_value(Value* v);
ValueNode* free_value_node(ValueNode* node);
int in_linked_list(ValueNode* head, Value* v);

// Operation on two structures in forward pass
Value* add(Value* a, Value* b);
Value* mul(Value* a, Value* b);
Value* power(Value* a, double exponent);
Value* relu(Value* a);
Value* tangenth(Value* a);
Value* softmax(Value* a);
Value* logarithm(Value* a);
Value* matrix_mul(Value* a);
Value* reduce_sum(Value* a);

// Operations for backward pass
void backward(Value* this);
void build_topo(Value* v, ValueNode** topo, ValueNode** visited);
void add_backward(Value* this);
void mul_backward(Value* this);
void power_backward(Value* this);
void relu_backward(Value* this);
void tangenth_backward(Value* this);
void softmax_backward(Value* this);
void logarithm_backward(Value* this);
void matrix_mul_backward(Value* this);
void reduce_sum_backward(Value* this);

#endif
