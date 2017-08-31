/*
The only thing that worries me in this code is the duplicate elements
I have not considered the equal cases. Amend it for them.
*/

#ifndef _UTILS

#define _UTILS
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#endif

using namespace std;

vector<int> find_subarray(vector<int> arr){
  vector<int> output;
  int first_index, second_index;
  for(int i=1; i<arr.size(); i++)
  {

    if(arr[i]<arr[i-1])
    {
      first_index = i;
      break;
    }
  }
  for(int i=arr.size()-2; i>=0; i--)
  {
    if(arr[i]<arr[i-1])
    {
      second_index = i;
      break;
    }
  }
  cout<<"The first index is "<<first_index<<" and the second index is "<<second_index;
  int min_val, max_val;
  min_val = arr[first_index];
  max_val = arr[first_index];
  for(int i = first_index;i<=second_index; i++)
  {
    if(min_val>arr[i])
    {
      min_val = arr[i];
    }
    if(max_val<arr[i])
    {
      max_val = arr[i];
    }
  }
  cout<<"The min value is "<<min_val<<" and the max value is "<<max_val;

  for(int i = 0; i<first_index; i++){
    if(arr[i]>min_val)
    {
      first_index = i;
      break;
    }
  }
  for(int i = arr.size()-1; i>second_index; i--){
    if(arr[i]<max_val)
    {
      second_index = i;
      break;
    }
  }
  output.push_back(first_index);
  output.push_back(second_index);
  return output;
}
