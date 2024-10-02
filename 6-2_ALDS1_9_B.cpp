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
    
    void ins(int x)
    {
        this->heap.push_back(x);
    }
    
    void buildMaxHeap()
    {
        for (int i = getParentIndex(size); i >= 0; i--)
        {
            maxHeapify(i);
        }
    }
    
    void maxHeapify(int this_index)
    {
        int l_index = getLeftIndex(this_index);
        int r_index = getRightIndex(this_index);
        
        int largest_index = this_index;
        if ((heap[l_index] > heap[this_index]) && l_index != -1)
        {
            largest_index = l_index;
        }
        if ((heap[r_index] > heap[largest_index]) && r_index != -1)
        {
            largest_index = r_index;
        }

        if (largest_index != this_index)
        {
            swap(heap[this_index], heap[largest_index]);
            maxHeapify(largest_index);
        }
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

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << heap[i];
            if (i < (size - 1))
                cout << " ";
        }
        cout << endl;
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
    
    heap.buildMaxHeap();
    
    heap.print();
}