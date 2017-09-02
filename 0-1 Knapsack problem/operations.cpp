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

int knapsack(vector<int> wt, vector<int> val, int i, int j)
{
  if((i<=0)||(j<=0))
  {
    return 0;
  }
  else{
    int output = max(knapsack(wt, val,i-wt[j],j-1)+val[j],knapsack(wt, val, i, j-1));
    return output;
  }
}

int operations(vector<int> wt, vector<int> val,int max_weight){
  int n = wt.size();
  int result;
  result = knapsack(wt, val, max_weight, n-1);
  return result;
}
