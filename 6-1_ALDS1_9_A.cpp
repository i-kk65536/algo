#include<iostream>
#include<vector>

using namespace std;

class Heap
{
private:
    int size;
    vector<int> heap;
public:
    Heap(int size)
    {
        this->size = size;
    }
    
    int getKey(int index)
    {
        return this->heap.at(index);
    }
    
    int getParentIndex(int index)
    {
        if (index == 0)
            return -1;
        int parent_index;
        parent_index = (index - 1) / 2;
        return parent_index;
    }

    int getLeftIndex(int index)
    {
        int left_index = 2 * index + 1;
        if (left_index > size - 1)
            return -1;
        return left_index;
    }

    int getRightIndex(int index)
    {
        int right_index = 2 * index + 2;
        if (right_index > size - 1)
            return -1;
        return right_index;
    }
    
    void ins(int x)
    {
        this->heap.push_back(x);
    }
};

int main()
{
    int size;
    cin >> size;
    Heap heap(size);
    for (int i = 0; i < size; i++)
    {
        int tmp;
        cin >> tmp;
        heap.ins(tmp);
    }
    
    for (int i = 0; i < size; i++)
    {
        cout << "node " << i + 1 << ": ";
        cout << "key = " << heap.getKey(i) << ", ";
        int parent_index = heap.getParentIndex(i);
        if (parent_index != -1)
            cout << "parent key = " << heap.getKey(parent_index) << ", ";
        int left_index = heap.getLeftIndex(i);
        if (left_index != -1)
            cout << "left key = " << heap.getKey(left_index) << ", ";
        int right_index = heap.getRightIndex(i);
        if (right_index != -1)
            cout << "right key = " << heap.getKey(right_index) << ", ";
        cout << endl;
    }
}

