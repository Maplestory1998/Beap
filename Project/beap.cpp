#include "beap.h"
#include<iostream>
#include<math.h>

int beap::getHeight()
{
    int height = sqrt(2 * size); // realheight >= height
    int end = (height * (height + 1)) / 2;
    height += (end >= size) ? 0 : 1;

    return height;
}

/*base 0*/
pair<int, int> beap::getSpan(int height)
{
    int l = (height * (height - 1)) / 2;
    int r = (height * (height + 1)) / 2 - 1;
    return make_pair(l ,r);
}

void beap::fixInsert()
{
    int i = size - 1;
    int height = getHeight();

    while (i > 0)
    {
        int l = i - height;
        int r = l + 1;
        pair<int, int> span = getSpan(height - 1);
        int maxVal = i;
        if (l >= span.first && arr[l] > arr[maxVal])
            maxVal = l;
        if (r <= span.second && arr[r] > arr[maxVal])
            maxVal = r;
        if (maxVal != i)
        {
            swap(arr[i], arr[maxVal]);
            i = maxVal;
            height--;
        }
        else break;
    }
}

void beap::fixExtract()
{
    int i = 0;
    int curHeight = 1;
    while (i < size)
    {
        int l = i + curHeight;
        int r = l + 1;
        int minVal = i;
        if (l < size && arr[l] < arr[minVal])
            minVal = l;
        if (r < size && arr[r] < arr[minVal])
            minVal = r;
        if (minVal != i)
        {
            swap(arr[i], arr[minVal]);
            i = minVal;
            curHeight++;
        }
        else break;
    }
}

int beap::getIndex(int x)
{
    int height = getHeight();
    int begin = getSpan(height - 1).second + 1;

    int row = 0;
    int col = height - 2;
    if (begin + height == size)
        col += 1;

    int p = (row + col) * (row + col + 1) / 2 + col;
    while ( p >= 0 && p < size && arr[p] != x)
    {
        if (arr[p] > x)
        {
            col--;
            if(col < 0) return -1;
            p = (row + col) * (row + col + 1) / 2 + col;
        }
        else if (arr[p] < x)
        {
            row++;
            p = (row + col) * (row + col + 1) / 2 + col;
            if(p >= size)
            {
                col--;
                if(col < 0) return -1;
                p = (row + col) * (row + col + 1) / 2 + col;
            }
        }
    }

    return p;
}

int beap::minimum()
{
    if (empty())
    {
        //cout << "empty beap!" << endl;
        return -1;
    }
    return arr[0];
}

int beap::maximum()
{ 
    if (empty())
    {
        //cout << "empty beap!" << endl;
        return -1;
    }
    int height = getHeight();

    int begin = size - height;
    int res = arr[begin];
    for (int i = begin; i < size; i++)
        res = max(res, arr[i]);
    return res;

}

void beap::insert(int k)
{
    size++;
    if (arr.size() < size)
    {
        arr.push_back(k);
    }
    else arr[size - 1] = k;

    fixInsert();
}

int beap::extract()
{
    if (empty())
    {
        //cout << "empty beap!" << endl;
        return -1;
    }

    int res = arr[0];
    swap(arr[0], arr[size - 1]);
    size--;
    fixExtract();

    return res;
}

int beap::search(int x)
{
    int index = getIndex(x);
    if (index < 0 || index >= size)
    {
        //cout << "The key isn't exist!" << endl;
        return -1;
    }

    return arr[index];
}

void beap::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
