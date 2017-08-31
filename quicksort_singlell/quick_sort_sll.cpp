#ifndef _UTILS

#define _UTILS
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include "utils.h"
//std::ostream & o = (std::cout << "I am in main");
#endif
void quicksort(ListNode<int>* head, ListNode<int>* end)
{
  if(head == end)
  {
    return;
  }
  ListNode<int>* small;
  ListNode<int>* small_prev;
  ListNode<int>* run;
  ListNode<int>* run_prev;
  int part_val = head->val;
  small = head;
  run = head->next;
  run_prev = head;
  while(run->next!=end)
  {
    if(run->val<part_val)
    {
      run_prev->next = run->next;
      run->next = small;
      if(small==head)
      {
        small_prev = run;
      }
      small = run;
    }
    else{
      run_prev = run;
    }
    run = run->next;
  }
  quicksort(small, small_prev);
  quicksort(head->next, NULL);
}

ListNode<int>* quick_ll(ListNode<int>* head)
{
  int min_val;
  ListNode<int>* temp;
  ListNode<int>* min_ptr;
  temp = head;
  min_val = temp->val;
  temp = temp->next;
  while(temp->next!=NULL)
  {
    if(min_val>temp->val)
    {
      min_val = temp->val;
      min_ptr = temp;
    }
    temp = temp->next;
  }
  if(min_val>temp->val)
  {
    min_val = temp->val;
    min_ptr = temp;
  }
  cout<<"The minimum value is "<<min_val<<" with address as "<<min_ptr;
  quicksort(head, NULL);
  return min_ptr;
}
