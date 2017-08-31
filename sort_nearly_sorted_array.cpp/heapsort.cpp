/*
This code implements min heap.
*/

#include<iostream>
#include<vector>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(vector<int> &arr, int root, int size)
{
    int smallest = root;
    // cout<<"I am heapifying it"<<arr[0];
    //cout<<"The size is "<<size<<" and the root is "<<root;
    // getchar();
    int left = root*2+1;
    int right = root*2+2;
    //cout<<"\n The root, left and right are "<<root<<left<<right;
    if((left>size)||(right>size))
    {
      return;
    }
    if((left<size)&&(arr[left]<arr[root]))
    {
        smallest = left;
    }
    if((right<size)&&(arr[right]<arr[smallest]))
    {
        smallest = right;
    }
    if(smallest!=root)
    {
        //cout<<"Earlier root and smallest were "<<arr[root]<<" "<<arr[smallest];
        swap(&arr[smallest], &arr[root]);
        //cout<<"Now root and smallest were "<<arr[root]<<" "<<arr[smallest];
        //getchar();
        heapify(arr,smallest,arr.size());
    }
}

void build_heap(vector<int> &arr){
  int n = arr.size();
  cout<<n;
  for(int i=(n/2)-1; i>=0; i--)
  {
    //cout<<"\n I am heapifying it";
    heapify(arr, i, arr.size());
  }
}

void insert(vector<int> &arr, int val){
  arr.push_back(val);
  int n = arr.size();
  swap(arr[0], arr[n-1]);
  heapify(arr,0,n-1);
}

void remove_at_front(vector<int> &arr){
  arr.erase(arr.begin());
  build_heap(arr);
}

void heapsort(vector<int> &arr)
{
    int n = arr.size();
    build_heap(arr);
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr,0,i);
    }
}
/*
int main() {
  vector<int> arr = {12, 11, 13, 5, 6, 7};
  heapsort(arr);

  cout << "Sorted array is \n";
  printArray(arr);
  getchar();
	return 0;
}
*/
