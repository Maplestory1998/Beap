#include "Binaryheap.h"
#include <iostream>

void Binaryheap::heapify(int i)
{
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	int miniVal = i;
	if (l < size && heap[l] < heap[miniVal])
		miniVal = l;
	if (r < size && heap[r] < heap[miniVal])
		miniVal = r;
	if (miniVal != i)
	{
		swap(heap[i], heap[miniVal]);
		heapify(miniVal);
	}

	return;
}

void Binaryheap::buildheap()
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(i);
	}
	return;
}

int Binaryheap::getIndex(int pos, int k)
{
	if (pos < size && heap[pos] == k)
		return pos;
	else if (pos >= size || heap[pos] > k) return -1;
	int l = pos * 2 + 1;
	int r = pos * 2 + 2;

	int lres = getIndex(l, k);
	int rres = getIndex(r, k);

	return max(lres, rres);
}

int Binaryheap::minimum()
{
	if (empty() )
	{
		//cout << "empty heap" << endl;
		return -1;
	}
	return heap[0];
}

int Binaryheap::maximum()
{
	if (empty())
	{
		//cout << "empty heap!" << endl;
		return -1;
	}
	int begin = size / 2 - 1;
	int ret = heap[begin];
	for (int i = begin; i < size; i++)
	{
		ret = max(heap[i], ret);
	}
	return ret;
}

void Binaryheap::insert(int k)
{
	size++;
	if (size <= capacity)
		heap[size - 1] = k;
	else
	{
		heap.push_back(k);
		capacity = heap.size();
	}
	int pos = size - 1;
	int ppos = (pos + 1) / 2 - 1;
	while (pos > 0 && heap[ppos] > heap[pos])
	{
		swap(heap[pos], heap[ppos]);
		pos = ppos;
		ppos = (pos + 1) / 2 - 1;
	}
	return;
}

int Binaryheap::extract()
{
	if (empty())
	{
		//cout << "empty heap" << endl;
		return -1;
	}
	int res = heap[0];
	swap(heap[0], heap[size - 1]);
	size--;
	heapify(0);

	return res;
}

int Binaryheap::search(int k)
{
	int index = getIndex(0, k);
	if (index < 0)
	{
		//cout << "not exist " << endl;
		return -1;
	}
	return heap[index];
}

void Binaryheap::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << heap[i] << " " << endl;
	}
}

