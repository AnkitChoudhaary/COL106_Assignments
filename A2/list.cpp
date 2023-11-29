#include <iostream>
#include "list.h"

using namespace std;

List::List()
{
    size = 0;
    sentinel_head = new Node(true);
    sentinel_tail = new Node(true);
    sentinel_head->next = sentinel_tail;
    sentinel_tail->prev = sentinel_head;
    sentinel_head->prev = nullptr;
    sentinel_tail->next = nullptr;
}
List::~List()
{
    while (size)
    {
        delete_tail();
    }
    delete sentinel_head;
    delete sentinel_tail;
}
void List::insert(int a)
{
    size += 1;

    Node *temp = new (nothrow) Node(a, this->sentinel_tail, this->sentinel_tail->prev);
    if (temp == nullptr)
    {
        throw runtime_error("Out of memory");
    }
    this->sentinel_tail->prev->next = temp;
    this->sentinel_tail->prev = temp;
    // delete temp;
    return;
}
int List::delete_tail()
{
    if (this->sentinel_tail->prev->is_sentinel_node())
    {
        throw runtime_error("Empty Stack");
    }
    int v = this->sentinel_tail->prev->get_value();
    this->sentinel_tail = this->sentinel_tail->prev;
    delete this->sentinel_tail->next;
    Node *temp = new Node(true);
    temp->prev = this->sentinel_tail->prev;
    this->sentinel_tail->prev->next = temp;
    sentinel_tail = temp;
    this->size -= 1;
    return v;
}
int List::get_size()
{
    return this->size;
}
Node *List::get_head()
{
    return this->sentinel_head;
}