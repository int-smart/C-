#ifndef _UTILS

#define _UTILS
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include "../utils.h"
#include "operations.cpp"
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

vector<int> create_vector(){
  //vector<int> arr = {1, 1, 11, 100, 13, 5, 6, 6};
  //vector<int> arr = {12, 11, 100, 13, 5, 6, 7};
  vector<int> arr ={10, 20, 30};
  //vector<int> arr2 = {1,3,4,40,38,36,42,44};
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
  vector<int> wt = create_vector();
  vector<int> val = {60, 100, 120};
  int max_weight = 50;
  int result = operations(wt, val, max_weight);
  cout <<"The maximum value is "<<result;
  getchar();
	return 0;
}
