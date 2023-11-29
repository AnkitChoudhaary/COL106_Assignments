#include <iostream>
#include "node.h"
using namespace std;

Node::Node(bool sentinel) : is_sentinel(true)
{
    this->is_sentinel = sentinel;
    this->next = nullptr;
    this->prev = nullptr;
}
Node::Node(int v, Node *nxt, Node *prv)
{
    this->is_sentinel = false;
    this->value = v;
    this->next = nxt;
    this->prev = prv;
}
bool Node::is_sentinel_node()
{
    return this->is_sentinel;
}
int Node::get_value()
{
    return this->value;
}