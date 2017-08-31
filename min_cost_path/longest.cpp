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

int min_cost(vector<vector<int>> cost){
  int n = cost.size();
  int n1 = cost[0].size();
  vector<vector<int>> min_cost(n, vector<int>(n1));    //all values default initialized to zero

  for (int i = 0; i<n; i++)
  {
    for(int j = 0; j<n1; j++)
    {
      if((i-1<0)&&(j-1>=0))
      {
        min_cost[i][j] = min_cost[i][j-1]+cost[i][j];
      }
      else if((j-1<0)&&(i-1>=0))
      {
        min_cost[i][j] = min_cost[i-1][j]+cost[i][j];
      }
      else if((j-1<0)&&(i-1<0))
      {
        min_cost[i][j] = cost[i][j];
      }
      else{
        min_cost[i][j] = min({min_cost[i-1][j], min_cost[i][j-1], min_cost[i-1][j-1]})+cost[i][j];
      }
    }
  }

  //cout<<"I have done it once"<<min_cost[n-1][n1-1];
  //getchar();
  for(int i=0;i<n;i++)
  {
    for(int j = 0; j<n1; j++)
    {
      cout<<min_cost[i][j]<<" ";
    }
    cout<<"\n";
  }
  return min_cost[n-1][n1-1];
}
