#include <iostream>
#include "stack_c.h"
using namespace std;
Stack_C::Stack_C()
{
    stk = new (nothrow) List();
    if (stk == nullptr)
    {
        throw runtime_error("Out of memory");
    }
}
Stack_C::~Stack_C()
{
    delete stk;
}
void Stack_C ::push(int x)
{
    stk->insert(x);
}
int Stack_C::pop()
{
    return stk->delete_tail();
}
int Stack_C::get_element_from_top(int a)
{
    if (a > (stk->get_size() - 1) || a < 0)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        Node *p = stk->get_head();
        for (int i = 0; i < get_size() - a; i++)
        {
            p = p->next;
        }
        return p->get_value();
    }
}
int Stack_C::get_element_from_bottom(int a)
{
    if (a > (stk->get_size() - 1) || a < 0)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        Node *p = stk->get_head();
        for (int i = 0; i <= a; i++)
        {
            p = p->next;
        }
        return p->get_value();
    }
}
void Stack_C::print_stack(bool top_or_bottom)
{
    bool t = top_or_bottom;
    Node *a = this->stk->get_head();
    int s = this->stk->get_size();
    if (!t)
    {
        while (!a->next->is_sentinel_node())
        {
            cout << a->next->get_value() << endl;
            a = a->next;
        }
    }
    else
    {
        int *arr = new int[s];
        int z = 0;
        while (!a->next->is_sentinel_node())
        {
            arr[z] = a->next->get_value();
            a = a->next;
            z++;
        }
        z--;
        for (z; z >= 0; z--)
        {
            cout << arr[z] << endl;
        }
        delete[] arr;
    }
}
int Stack_C::add()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int a = pop();
    int b = pop();
    push((b + a));
    return (b + a);
}
int Stack_C::subtract()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int a = pop();
    int b = pop();
    push((b - a));
    return (b - a);
}
int Stack_C::multiply()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int a = pop();
    int b = pop();
    push((b * a));
    return (b * a);
}
int Stack_C::divide()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int a = pop();
    int b = pop();
    if (a == 0)
    {
        throw runtime_error("Divide by Zero Error");
    }
    else
    {
        int r = b / a;
        if (a * b < 0 && float(a) / float(b) != r)
        {
            r--;
        }
        push(r);
        return (r);
    }
}
int Stack_C::get_size()
{
    return stk->get_size();
}
List *Stack_C::get_stack()
{
    return stk;
}