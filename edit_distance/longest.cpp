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

int edit_distance(string arr, string arr1){
  int n = arr.size();
  int n1 = arr1.size();
  vector<vector<int>> count(n+1, vector<int>(n1+1));    //all values default initialized to zero

  for (int i = 0; i<=n; i++)
  {
    for(int j = 0; j<=n1; j++)
    {
      if(i==0)
      {
        count[i][j] = j;
      }
      else if(j==0)
      {
        count[i][j] = i;
      }
      else if(arr[i-1]==arr1[j-1])
      {
        count[i][j] = count[i-1][j-1];
      }
      else{
        count[i][j] = min({1+count[i-1][j], 1+count[i][j-1], 1+count[i-1][j-1]});
      }
    }
  }

  cout<<"I have done it once"<<count[n][n1];
  getchar();
  return count[n][n1];
}
