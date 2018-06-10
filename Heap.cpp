#include<bits/stdc++.h>

using namespace std;

long long int heap[100000];

long long heap_size = -1;

void heapify(int x)
{
	int left = x*2 + 1;
	int right = x*2 + 2;
	if(left <= heap_size && heap[x] > heap[left]) {
		swap(heap[x], heap[left]);
		heapify(left);
	} else if(right <= heap_size && heap[x] > heap[right]) {
		swap(heap[x], heap[right]);
		heapify(right);
	}
}


int getParent(int x)
{
	return (x % 2 == 0) ? x/2 -1 : x/2;
}

void insert(long long int x)
{
    heap_size++;
    
    int i = heap_size;
    
    heap[i] = x;

    while(i != 0 && heap[i] < heap[getParent(i)]) {
    	swap(heap[i], heap[getParent(i)]);
    	i = getParent(i);
    }

}


void deleteMin()
{
	heap[0] = heap[heap_size];
	heap_size--;
	heapify(0);
}


int main()
{
    insert(2);
    insert(3);
    insert(5);
    deleteMin();
    deleteMin();
    for(int i = 0; i <= 10; ++i) {
    	cout << heap[i] << " ";
    }
    cout << endl;
    cout << heap[0] << endl;

}