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

// int longest(vector<int> arr){
//   int n = arr.size();
//   vector<int> count(n, 1);
//
//   for (int i = 1; i<n; i++)
//   {
//     vector<int> temp;
//     for(int j =0; j<i; j++)
//     {
//       if(arr[i]>arr[j])
//       {
//         int temp_data = count[i]+count[j];
//         temp.push_back(temp_data);
//       }
//       else{
//         if(temp.size()==0)
//         {
//           temp.push_back(count[j]);
//         }
//       }
//     }
//     printArray(temp);
//     cout<<"I have done it once"<<count[i];
//     getchar();
//     count[i] = *(max_element(temp.begin(), temp.end()));
//   }
//   return count[n-1];
// }

int longest(vector<int> arr){
  int n = arr.size();
  vector<int> result(n);
  vector<int> count(n, 1);
  vector<int> dec_count(n, 1);
  for (int i = 1; i<n; i++)
  {
    vector<int> temp;
    for(int j =0; j<i; j++)
    {
      if(arr[i]>arr[j])
      {
        int temp_data = count[i]+count[j];
        temp.push_back(temp_data);
      }
      else{
        if(temp.size()==0)
        {
          temp.push_back(count[j]);
        }
      }
    }
    count[i] = *(max_element(temp.begin(), temp.end()));
  }
  for (int i = n-2; i>=0; i--)
  {
    vector<int> temp;
    for(int j =n-1; j>i; j--)
    {
      if(arr[i]>arr[j])
      {
        int temp_data = dec_count[i]+dec_count[j];
        temp.push_back(temp_data);
      }
      else{
        if(temp.size()==0)
        {
          temp.push_back(dec_count[j]);
        }
      }
    }
    dec_count[i] = *(max_element(temp.begin(), temp.end()));
  }
  for(int i = 0; i<n; i++)
  {
   result[i] = count[i] + dec_count[i];
  }
  return *(max_element(result.begin(), result.end()))-1;
}
