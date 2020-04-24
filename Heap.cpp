//============================================================================
// Name        : Heap.cpp
// Author      : Smit Modi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
	int *harr;
	int cap;
	int heap_size;
public:
	MinHeap(int cap);
	void MinHeapify(int );
	int parent(int i)
	{
		return (i-1)/2;
	}
	int left(int i)
	{
		return (2*i+1);
	}
	int right(int i)
	{
		return (2*i+2);
	}
	int extractMin();
	void decreaseKey(int i,int val);
	int getMin()
	{
		return harr[0];
	}
	void deleteKey(int i);
	void insertKey(int k);
};

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

MinHeap::MinHeap(int capacity)
{
	heap_size = 0;
	cap = capacity;
	harr = new int[cap];
}

void MinHeap::insertKey(int k)
{
	if(heap_size == cap)
	{
		cout << "Heap Full!" << endl;
		return ;
	}
	heap_size++;
	int i = heap_size-1;
	harr[i] = k;
	while(i!=0 && harr[parent(i)]>harr[i])
	{
		swap(&harr[i],&harr[parent(i)]);
		i = parent(i);
	}
}

void MinHeap::decreaseKey(int i,int val)
{
	harr[i] = val;
	while(i!=0 && harr[parent(i)]>harr[i])
	{
		swap(&harr[i],&harr[parent(i)]);
		i = parent(i);
	}
}

int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

int main() {
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();
	return 0;
}
