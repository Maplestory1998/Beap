#pragma once
#ifndef BEAP_H
#define BEAP_H

#include<vector>
using namespace std;

class beap
{
private:
	vector<int> arr;
	int size = 0;

	bool empty() { return size == 0; }
	int getHeight();

	/*base 0*/
	pair<int, int> getSpan(int height);

	void fixInsert();
	void fixExtract();

	/* return index of x*/
	int getIndex(int x);

public:
	beap():size(0) {}
	beap(vector<int> &vec)
	{
		int n = vec.size();
		for (int i = 0; i < n; i++)
		{
			insert(vec[i]);
		}
	}

	int minimum();
	int maximum();
	void insert(int k);
	int extract();
	int search(int x);
	void print();

};

#endif // !BEAP_H


