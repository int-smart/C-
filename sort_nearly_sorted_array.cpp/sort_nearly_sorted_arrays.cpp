#ifndef _UTILS

#define _UTILS
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include "../utils.h"
//std::ostream & o = (std::cout << "I am in main");
#endif
#include "heapsort.cpp"
using namespace std;

vector<int> sort_arr(vector<int> arr, int k=2){
  vector<int> result;
  vector<int> arr_k;
  arr_k.assign(arr.begin(),arr.begin()+k+1);
  for(int i = 0; i<arr.size()-k-1; i++)
  {
    printArray(arr_k);
    build_heap(arr_k);
    cout<<"The result is "<<arr_k[0]<<"\n";
    result.push_back(arr_k[0]);
    arr_k.erase(arr_k.begin());
    arr_k.push_back(arr[k+1+i]);
    getchar();
  }
  build_heap(arr_k);
  cout<<"The result is "<<arr_k[0]<<"\n";
  result.push_back(arr_k[0]);
  arr_k.erase(arr_k.begin());
  sort(arr_k.begin(),arr_k.end());
  for(int i = 0; i<arr_k.size(); i++)
  {
    result.push_back(arr_k[i]);
  }
  return result;
}
