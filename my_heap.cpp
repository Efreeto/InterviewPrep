
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Heap
{
    vector<int> harr;
public:
    int GetMax();
    int PopMax();
    void Push(int input);
    void Print();
};

int Heap::GetMax()
{
    if (harr.empty())
        return -1;  // error
    return harr[0];
}

void Heap::Push(int input)
{
    harr.push_back(input);
    int child = harr.size() - 1;
    while (child)
    {
        int parent = (child - 1) / 2;

        if (harr[child] < harr[parent])
            break;
        swap(harr[child], harr[parent]);

        child = parent;
    }
}

int Heap::PopMax()
{
    int output = GetMax();
    if (output == -1)
        return -1;

    int parent = 0;
    harr[parent] = harr.back();
    while (parent < harr.size())
    {
        int child_left = parent * 2 + 1;
        int child_right = child_left + 1;
        int child_to_compare;

        if (child_left < harr.size() && child_right < harr.size())
        {
            if (harr[child_left] < harr[child_right])
            {
                child_to_compare = child_left;
            }
            else
            {
                child_to_compare = child_right;
            }
        }
        else if (child_left < harr.size())
        {
            child_to_compare = child_left;
        }
        else
        {
            break;  // we are at leaf node
        }

        if (harr[child_to_compare] < harr[parent])
            break;
        swap(harr[child_to_compare], harr[parent]);
        parent = child_to_compare;
    }
    harr.resize(harr.size() - 1);   // delete the last element
    return output;
}

void Heap::Print()
{
    if (harr.empty())
    {
        cout << endl;
        return;
    }

    queue<int> print_stack;
    print_stack.push(0);
    while (!print_stack.empty())
    {
        int parent = print_stack.front();
        print_stack.pop();
        cout << harr[parent] << '-';

        int child_left = parent * 2 + 1;
        int child_right = child_left + 1;
        if (child_left < harr.size())
            print_stack.push(child_left);
        if (child_right < harr.size())
            print_stack.push(child_right);
    }
    cout << endl;
}

void main()
{
    Heap my_heap;
    my_heap.Print();

    my_heap.Push(3);
    my_heap.Print();

    my_heap.Push(4);
    my_heap.Push(2);
    my_heap.Print();

    my_heap.Push(7);
    my_heap.Push(1);
    my_heap.Push(3);
    my_heap.Print();

    cout << "Max popped: " << my_heap.PopMax() << endl;
    my_heap.Print();

    cout << "Max popped: " << my_heap.PopMax() << endl;
    my_heap.Print();

    my_heap.Push(4);
    my_heap.Push(2);
    my_heap.Print();

    cout << "Max popped: " << my_heap.PopMax() << endl;
    my_heap.Print();
}