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

int coin_change(vector<int> coins, int target){
  int n = coins.size();
  int result;
  vector<vector<int>> ways(target, vector<int>(n));
  for(int i = 0; i<target; i++)
  {
    for(int j=0; j<n; j++)
    {
      ways[i][j] = ways[i][] + ways[][];
    }
  }
  return result;
}
