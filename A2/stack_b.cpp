#include <iostream>
#include <stdexcept>
#include "stack_b.h"
using namespace std;
Stack_B::Stack_B()
{
    size = 0;
    capacity = 1024;
    stk = new (nothrow) int[1024];
    if (stk == nullptr)
    {
        throw runtime_error("Out of memory");
    }
}
Stack_B::~Stack_B()
{
    delete[] stk;
}
void Stack_B ::push(int x)
{
    if (size >= capacity)
    {
        int *a = new (nothrow) int[2 * capacity];
        if (a == nullptr)
        {
            throw runtime_error("Out of memory");
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                a[i] = stk[i];
            }
        }
        capacity = 2 * capacity;
        delete[] stk;
        stk = a;
    }
    stk[size] = x;
    size++;
}
int Stack_B ::pop()
{
    if (size <= 0)
    {
        throw runtime_error("Empty Stack");
    }
    if (size <= capacity / 4 && capacity / 4 >= 1024)
    {
        int temp = stk[size - 1];
        int *a = new (nothrow) int[capacity / 2];
        if (a == nullptr)
        {
            throw runtime_error("Out of memory");
        }
        capacity = capacity / 2;
        for (int i = 0; i < size - 1; i++)
        {
            a[i] = stk[i];
        }
        size--;
        delete[] stk;
        stk = a;
        return temp;
    }
    else
    {
        size--;
        return stk[size];
    }
}
int Stack_B::get_element_from_top(int idx)
{
    if (idx >= 0 && idx < size)
    {
        return (stk[size - 1 - idx]);
    }
    else
    {
        throw runtime_error("Index out of range");
    }
}

int Stack_B::get_element_from_bottom(int idx)
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
void Stack_B::print_stack(bool top_or_bottom)
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

int Stack_B::add()
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
int Stack_B::subtract()
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
int Stack_B::multiply()
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
int Stack_B::divide()
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
int *Stack_B::get_stack()
{
    return stk;
}
int Stack_B::get_size()
{
    // cout << capacity << " ";
    return size;
}