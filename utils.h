#pragma once
#ifndef _UTILS
#define _UTILS
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
//std::ostream & o = (std::cout << "I am in main");
#endif

using namespace std;

template <typename ElemType>
struct ListNode{
  ElemType val;
  ListNode *next;
  ListNode(ElemType x) : val(x), next(NULL) {}
};

template <typename ElemType>
class LinkedList{
public:
  LinkedList();
  ~LinkedList();
  void add(ElemType val);
  int get_size();
  void printList();
  ListNode<ElemType>* get_head();
private:
  int size;
  ListNode<ElemType> *head;
};

template<typename ElemType>
LinkedList<ElemType>::LinkedList(){
  head = NULL;
  size = 0;
}

template<typename ElemType>
LinkedList<ElemType>::~LinkedList(){
}

template<typename ElemType>
ListNode<ElemType>* LinkedList<ElemType>::get_head(){
  return head;
}


template <typename ElemType>
void LinkedList<ElemType>::add(ElemType val){
  ListNode<ElemType> *l = new ListNode<ElemType>(val);
  if(head==NULL)
  {
    head = l;
    size = 1;
  }
  else{
    ListNode<ElemType> *temp = head;
    while(temp->next!=NULL)
    {
      temp = temp->next;
    }
    temp->next = l;
    size += 1;
  }
}

template <typename ElemType>
int LinkedList<ElemType>::get_size(){
  return size;
}

template <typename ElemType>
void LinkedList<ElemType>::printList()
{
  ListNode<ElemType> *temp = head;
  cout<<"The list is ";
  while(temp->next!=NULL)
  {
    cout<<" "<<temp->val;
    temp = temp->next;
  }
  cout<<" "<<temp->val;
}


void printArray(vector<int> arr)
{
    for (int i=0; i<arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int binarySearch(vector<int> arr, int l, int r, int x)
{
    int mid = (r+l)/2;
    if(l<=r)
    {
        mid = (l+r)/2;
        if(arr[mid] == x) return mid;
        else if (arr[mid]<x) return binarySearch(arr, mid+1, r, x);
        else return binarySearch(arr, l, mid-1, x);
    }
    return -1;
}
