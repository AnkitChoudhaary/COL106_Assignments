#include <iostream>
#include <stdexcept>
#include "stack_a.h"
using namespace std;
Stack_A::Stack_A()
{
    size = 0;
}
void Stack_A::push(int a)
{
    if (get_size() >= 1024)
    {
        throw runtime_error("Stack Full");
    }
    else
    {
        stk[size] = a;
        size++;
    }
}
int Stack_A::pop()
{
    if (size > 0)
    {
        size--;
        return stk[size];
    }
    else
    {
        throw runtime_error("Empty Stack");
    }
}
int Stack_A::get_element_from_top(int idx)
{
    if (idx < size && idx >= 0)
    {
        return (stk[size - 1 - idx]);
    }
    else
    {
        throw runtime_error("Index out of range");
    }
}

int Stack_A::get_element_from_bottom(int idx)
{
    if (idx >= 0 && idx < size)
    {
        return (stk[idx]);
    }
    else
    {
        throw runtime_error("Index out of range");
    }
}

void Stack_A::print_stack(bool top_or_bottom)
{
    if (top_or_bottom)
    {
        for (int i = 0; i < size; i++)
        {
            cout << (stk[size - 1 - i]) << "\n";
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << (stk[i]) << "\n";
        }
    }
    return;
}

int Stack_A::add()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int a = pop();
        int b = pop();
        push((a + b));
        return ((a + b));
    }
}
int Stack_A::subtract()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int a = pop();
        int b = pop();
        push((b - a));
        return ((b - a));
    }
}
int Stack_A::multiply()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int a = pop();
        int b = pop();
        push((a * b));
        return ((a * b));
    }
}
int Stack_A::divide()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int a = pop();
        int b = pop();
        if (a == 0)
        {
            throw runtime_error("Divide by Zero Error");
        }
        else
        {
            int r = b / a;
            if (a * b < 0 && float(b) / float(a) != r)
            {
                r--;
            }
            push(r);
            return (r);
        }
    }
}
int *Stack_A::get_stack()
{
    return stk;
}
int Stack_A::get_size()
{
    return size;
}
