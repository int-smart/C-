/*
The eproblem with this code seems to be that
when the nodes are just one value large I am not
considering that as I am assuming everything
is going into the NULL loop. Check That.

Update : The only thing that is not working right now is that the
number of elements are decreasing maybe I am not running the loops
correctly.
*/


#ifndef _UTILS

#define _UTILS
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include "utils.h"
#endif

using namespace std;

template <typename ElemType>
ListNode<ElemType>* merge_sort_ll(ListNode<ElemType> *head)
{
  int size=0;
  if(head->next == NULL)
  {
    return head;
  }
  ListNode<ElemType> *temp = head;
  ListNode<ElemType> *temp1;
  while(temp->next!=NULL)
  {
    size++;
    temp = temp->next;
  }
  size++;
  int left_size = size/2;
  int right_size = size-left_size;
  temp = head;
  for(int i=0; i<left_size; i++){
    temp1 = temp;
    temp = temp->next;
  }
  temp1->next = NULL;
  head = merge_sort_ll(head);
  temp = merge_sort_ll(temp);
  head = merge_ll(head, temp);
  return head;
}

template <typename ElemType>
ListNode<ElemType>* merge_ll(ListNode<ElemType> *left, ListNode<ElemType> *right){
  ListNode<ElemType> *head;
  ListNode<ElemType> *temp;
  head = NULL;
  if((left->val<right->val)&&(head==NULL))
  {
    head = left;
    temp = left;
    if((left->next==NULL)&&(right->next==NULL))
    {
      temp->next = right;
      return head;
    }
    left = left->next;
  }
  else if((left->val>right->val)&&(head==NULL))
  {
    head = right;
    temp = right;
    if((left->next==NULL)&&(right->next==NULL))
    {
      temp->next = left;
      return head;
    }
    right = right->next;
  }
  while((left->next!=NULL)&&(right->next!=NULL))
  {
    if(left->val<right->val)
    {
      temp->next = left;
      temp = left;
      left = left->next;
    }
    else if(left->val>right->val)
    {
      temp->next = right;
      temp = right;
      right = right->next;
    }
  }

  if(left->next!=NULL)
  {
    while((right->val>left->val)&&(left->next!=NULL))
    {
      temp->next = left;
      temp = left;
      left = left->next;
    }
    temp->next = right;
    temp = right;
    if(left->next!=NULL)
    {
      while(left->next!=NULL)
      {
        temp->next = left;
        temp = left;
        left = left->next;
      }
    }
  }

  if(right->next!=NULL)
  {
    while((left->val>right->val)&&(right->next!=NULL))
    {
      temp->next = right;
      temp = right;
      right = right->next;
    }
    temp->next = left;
    temp = left;
    if(right->next!=NULL)
    {
      while(right->next!=NULL)
      {
        temp->next = right;
        temp = right;
        right = right->next;
      }
    }
  }

  return head;
}
