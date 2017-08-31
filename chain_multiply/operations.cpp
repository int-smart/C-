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

// int operations(vector<int> arr){
//   int n = arr.size();
//   int result;
//   vector<vector<int>> ways(target, vector<int>(n));
//   for(int i = 0; i<target; i++)
//   {
//     for(int j=0; j<n; j++)
//     {
//       ways[i][j] = ways[i][] + ways[][];
//     }
//   }
//   return result;
// }
int find_op(vector<int> arr, int i, int j)
{
  if(j-i<=1)
  {
    return 0;
  }
  else{
    return [](vector<int> arr, int i,int j){
      vector<int> operate;
      for(int k=i+1; k<j; k++)
      {
        int value = find_op(arr,i,k)+find_op(arr,k,j)+arr[i]*arr[j]*arr[k];
        operate.push_back(value);
      }
      int output = *(min_element(operate.begin(), operate.end()));
      return output;
    }(arr, i, j);
  }
}

int operations(vector<int> arr){
  int n = arr.size();
  int result;
  result = find_op(arr, 0, n-1);
  return result;
}
