#include "Binaryheap.h"
#include "beap.h"
#include <iostream>
#include <random>
#include <queue>
#include <algorithm>


static default_random_engine e;
static uniform_int_distribution<unsigned> u(0, 1000);

bool testheap()
{
	/* get random data*/
	vector<int> vec(1000, 0);
	deque<int> q;
	for (int i = 0; i < 1000; i++)
	{
		vec[i] = u(e);
		q.push_back(vec[i]);
	}
	cout << "Test heap:" << endl;

	Binaryheap heap(vec);
	sort(q.begin(), q.end());

	bool res = true;

	for (int i = 0; i < 1000; i++)
	{
		/* min*/
		if (heap.minimum() != q.front()) res = false; 

		/* max */
		if (heap.maximum() != q.back()) res = false;

		/*insert*/
		int temp = u(e);
		q.push_back(temp);
		sort(q.begin(), q.end());
		heap.insert(temp);
		int x = heap.minimum();
		int y = q.front();
		if (x != y) res = false;

		///*extract*/
		heap.extract();
		q.pop_front();

		/*search*/
		int tmp2 = rand() % 1000;
		int t1 = heap.search(tmp2);
		auto t2 = find(q.begin(), q.end(), tmp2);

		if( (t1 != -1 && t2 == q.end()) || t1 == -1 && t2 != q.end() ) res = false;
		
	}
	return res;

}

bool testbeap()
{
	/* get random data*/
	vector<int> vec(1000, 0);
	deque<int> q;
	for (int i = 0; i < 1000; i++)
	{
		vec[i] = u(e);
		q.push_back(vec[i]);
	}
	cout << "Test beap:" << endl;
	

	beap bp(vec);
	sort(q.begin(), q.end());

	bool res = true;

	for (int i = 0; i < 1000; i++)
	{
		/* min*/
		if (bp.minimum() != q.front()) res = false;

		/* max */
		if (bp.maximum() != q.back()) res = false;

		/*insert*/
		int temp = u(e);
		q.push_back(temp);
		sort(q.begin(), q.end());
		bp.insert(temp);
		int x = bp.minimum();
		int y = q.front();
		if (x != y) res = false;

		///*extract*/
		bp.extract();
		q.pop_front();

		/*search*/
		int tmp2 = rand() % 1000;
		int t1 = bp.search(tmp2);
		auto t2 = find(q.begin(), q.end(), tmp2);

		if ((t1 != -1 && t2 == q.end()) || t1 == -1 && t2 != q.end()) res = false;

	}
	
	return res;

}

bool test()
{
	/* get random data*/
	vector<int> vec(1000, 0);
	deque<int> q;
	for (int i = 0; i < 1000; i++)
	{
		vec[i] = u(e);
	}
	cout << "Test:" << endl;

	Binaryheap hp(vec);
	beap bp(vec);

	bool res = true;

	for (int i = 0; i < 1000; i++)
	{
		/* min*/
		if (hp.minimum() != bp.minimum()) res = false;

		/* max */
		if (hp.maximum() != bp.maximum()) res = false;

		/*insert*/
		int temp = u(e);
		hp.insert(temp);
		bp.insert(temp);
		if (bp.maximum() != hp.maximum()) res = false;

		///*extract*/
		bp.extract();
		hp.extract();

		/*search*/
		int tmp2 = rand() % 1000;
		if(hp.search(tmp2) != bp.search(tmp2)) res = false;

	}

	return res;

}


int main()
{
	/* test for Binaryheap*/
	if (testheap())
	{
		cout << "heap is correct" << endl;
	}

	/* test for beap*/
	
	if (testbeap())
	{
		cout << "beap is correct" << endl;
	}
	
	/* test for Binaryheap adn beap*/
	
	if (test())
	{
		cout << "heap and beap are correct!" << endl;
	}


	return 1;
}