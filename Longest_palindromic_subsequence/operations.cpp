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

int find_len(string arr, int i, int j)
{
  if(j<i)
  {
    return 0;
  }
  else if(i==j)
  {
    return 1;
  }
  else{
    int output;
    if(arr[i] == arr[j])
    {
      output = find_len(arr, i+1, j-1) + 2;
    }
    else {
      output = max(find_len(arr, i+1, j),find_len(arr, i, j-1));
    }
    return output;
  }
}

int longest_seq(string arr){
  int n = arr.size();
  int result;
  result = find_len(arr, 0, n-1);
  return result;
}
