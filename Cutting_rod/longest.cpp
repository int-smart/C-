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

int max_val(vector<int> val, int target){
  if(target==0)
  {
    return 0;
  }
  vector<int> values;
  for (int i = 1; i<=val.size(); i++)
  {
    if(target-i>=0)
    {
      int value = max_val(val, target-i) + val[i-1];
      values.push_back(value);
    }
  }
  return *(max_element(values.begin(), values.end()));
}
