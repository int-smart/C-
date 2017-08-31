
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

int search_arr(vector<int> arr, int start, int stop, int target){
  int n = arr.size();
  int mid;
  while(start<stop)
  {
    mid = start+(stop-start)/2;
    if(arr[mid]==target)
    {
      return mid;
    }
    else if ((arr[mid+1]==target) && mid<stop)
    {
      return mid+1;
    }
    else if ((arr[mid-1]==target) && start<mid)
    {
      return mid-1;
    }
    if(arr[mid]<target)
    {
      start = mid+2;
    }
    else if(arr[mid]>target)
    {
      stop = mid-2;
    }
  }
  return -1;
}
