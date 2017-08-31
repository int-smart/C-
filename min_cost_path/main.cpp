/*
For this code I have checked it online the code is correct as the equations are correct. The code is running. Check for more test cases and edge cases
*/


#ifndef _UTILS

#define _UTILS
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include "../utils.h"
#include "longest.cpp"
//std::ostream & o = (std::cout << "I am in main");
#endif

using namespace std;

ListNode<int>* create_list(){
  LinkedList<int> list;
  list.add(5);
  list.add(7);
  list.add(3);
  list.add(9);
  list.add(1);
  list.add(200);
  list.add(21);
  //list.add(110);
  ListNode<int> *head = list.get_head();
  //list.printList();
  return head;
}

vector<vector<int>> create_vector(){
  //vector<int> arr = {1, 1, 11, 100, 13, 5, 6, 6};
  //vector<int> arr = {12, 11, 100, 13, 5, 6, 7};
  //vector<int> arr ={12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
  //vector<vector<int>> arr = {{1,2,3},{4,8,2},{1,5,3}};
  vector<vector<int>> arr = {{1,0,1},{1,5,1},{2,1,4}};
  //printArray(arr);
  //vector<int> arr3 = {1,3,2,4};
  //vector<int> output;
  //output = find_subarray(arr);
  //cout << "Sorted array is \n";
  //printArray(output);
  return arr;
}

void print_list_pointer(ListNode<int>* head){
  cout<<"The list is ";
  while(head->next!=NULL)
  {
    cout<<head->val<<" ";
    head = head->next;
  }
  cout<<head->val;
}

int main() {
  vector<vector<int>> arr;
  arr = create_vector();
  int result;
  //cout<<arr[1][1];
  result = min_cost(arr);
  cout<<"The result is "<<result;
  getchar();
	return 0;
}
