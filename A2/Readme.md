## In this assignment I implemented Stack using multiple data structure :
<ol>
   <li>Stack_A: A data structure with all properties of a stack implemented using *a fixed size array* of size 1024.</li>
    <li>Stack_B: A data structure with all properties of stack implemented *using dynamic array* that takes *O(1) amortized time complexity for one push/pop operation. </li>
  <li> Stack_C: A data structure with all properties of stack implemented using *Doubly linked list*</li>
</ol>

# Stack Operations
| Command                     | Function Description                                             |
| --------------------------- | ----------------------------------------------------------------- |
| `void push(int data)`       | Push the argument on the stack                                   |
| `int pop()`                 | Pop and return the top element of the stack                      |
| `int get_element_from_top(int idx)`    | Return the element at index idx from the top            |
| `int get_element_from_bottom(int idx)` | Return the element at index idx from the bottom         |
| `void print_stack(bool top)` | Print the elements of the stack, one number per line. If top = 1, start printing from the top, else bottom. |
| `int add()`                 | Pop and add the top two elements of the stack and push the result back onto the stack |
| `int subtract()`            | Pop the top two elements from the stack. Subtract the top element from the second element and push the results back onto the stack |
| `int multiply()`            | Pop two elements from the stack and multiply them, push the result back onto the stack |
| `int divide()`              | Pop two elements from the stack. Divide the second from the top element by the top element of the stack. Push the floor of the result, i.e. ⌊res⌋ back onto the stack. |
| `int* get_stack()`          | Return a pointer to the array used for the stack (for Part 1 and 2) |
| `List* get_stack()`         | Return a pointer to the Linked List used for the stack (for Part 3) |
| `int get_size()`            | Return the size of the stack                                      |

#### This is the stack implemented as a postfix calculator, so it was implemented with those functions.
