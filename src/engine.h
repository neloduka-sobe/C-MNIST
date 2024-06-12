#ifndef ENGINE_H
#define ENGINE_H

// Structure definition
typedef struct Value {
    double data;
    double grad;
    struct ValueNode* children; // Linked list of children
    int children_count;
    void (*backward)(struct Value* this);
} Value;

typedef struct ValueNode {
    Value* value;
    ValueNode* next;
} ValueNode;

// Functions declarations
// Function declarations
Value* create_value(double data, ValueNode* children, char* op);
ValueNode* add_child(ValueNode* head, Value* child);
Value* add(Value* a, Value* b);
Value* mul(Value* a, Value* b);
Value* pow_val(Value* a, double exponent);
Value* relu(Value* a);
void backward(Value* this);
void build_topo(Value* v, Value** topo, int* topo_size, int* visited, int* visited_size);
void add_backward(Value* this);
void mul_backward(Value* this);
void pow_backward(Value* this);
void relu_backward(Value* this);
void print_value(Value* v);
void free_value(Value* v);
void free_value_node(ValueNode* node);

#endif
