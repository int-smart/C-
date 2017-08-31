#ifndef _UTILS

#define _UTILS
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include "../utils.h"
//std::ostream & o = (std::cout << "I am in main");
#endif

using namespace std;

vector<int> k_closest(vector<int> arr,int k, int target){
  vector<int> result;
  int previous, next;
  int target_index = binarySearch(arr, 0, arr.size()-1, target);
  previous = target_index-1;
  next = target_index+1;
  while(result.size()<k)
  {
    if(abs(target-arr[previous])<abs(target-arr[next]))
    {
      result.push_back(arr[previous]);
      previous--;
    }
    else{
      result.push_back(arr[next]);
      next++;
    }
  }
  return result;
}
