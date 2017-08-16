
#include <iostream>

using namespace std;

struct Slot {
    int data;
    Slot* below;
};

class Stack {
    Slot* top;
public:
    Stack();
    void Push(int);
    int Pop();
    void Print();
};

Stack::Stack()
{
    top = nullptr;
}

void Stack::Push(int input)
{
    Slot* new_top = new Slot;
    new_top->data = input;
    new_top->below = top;
    top = new_top;
}

int Stack::Pop()
{
    int output = top->data;
    Slot* old_top = top;
    top = top->below;
    delete old_top;
    return output;
}

void Stack::Print()
{
    Slot* curr = top;
    while (curr)
    {
        cout << curr->data << " <- ";
        curr = curr->below;
    }
    cout << "top" << endl;
}

void main()
{
    Stack my_stack;
    my_stack.Push(3);
    my_stack.Push(5);
    my_stack.Print();
    my_stack.Pop();
    my_stack.Push(4);
    my_stack.Print();
}