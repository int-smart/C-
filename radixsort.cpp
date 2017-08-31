#ifndef _UTILS

#define _UTILS
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#endif

#include "counting_sort.cpp"
using namespace std;

void radixsort(vector<int> &arr)
{
  auto max_item = max_element(arr.begin(), arr.end());
  int max_value = *max_item;
  int divisor = ceil(sqrt(max_value));
  vector<vector<int>> intermediate(arr.size());
  auto it = intermediate.begin();
  for (int i = 0; i < arr.size(); i++) {
    int quotient = arr[i]/divisor;
    int remains = arr[i]%divisor;
    //cout<<quotient<<" and "<<remains<<"\n";
    auto element = it[i];
    element.push_back(quotient);
    element.push_back(remains);
    //Complete radix sort It has to be converted from one vector of vector of int of quotient and remainder in the same vector to two vectors of just quotients and remainders
    //so that counting sort can be easily applied. I am moving to other ones now. 
    //printArray(element);
  }

}
