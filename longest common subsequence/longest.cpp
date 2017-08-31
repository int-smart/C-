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

int longest_common(string arr, string arr1){
  int n = arr.size();
  int n1 = arr1.size();
  vector<vector<int>> count(n+1, vector<int>(n1+1));

  for (int i = 1; i<=n; i++)
  {
    vector<int> temp;
    for(int j = 1; j<=n1; j++)
    {
      if(arr[i-1]==arr1[j-1])
      {
        count[i][j] = 1+count[i-1][j-1];
      }
      else{
        count[i][j] = max(count[i-1][j], count[i][j-1]);
      }
    }
  }
  cout<<"I have done it once"<<count[n][n1];
  getchar();
  return count[n][n1];
}
