#pragma once
#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include<vector>

using namespace std;

class Binaryheap
{
private:
	vector<int> heap;
	int size = 0;       // current length
	int capacity = 0;   //max length of heap == heap.size()

	bool empty() { return size == 0; }
	void heapify(int i );
	void buildheap();
	int getIndex(int pos, int k); //return index 

public:
	Binaryheap():size(0), capacity(0){}
	Binaryheap(vector<int> nums)
	{
		size = nums.size();
		capacity = size;
		heap = nums;
		buildheap();
	}

	int minimum();
	int maximum();
	void insert(int k);
	int extract();
	int search(int k);

	void print();

};

#endif

