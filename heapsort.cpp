#include<iostream>
#include<vector>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(vector<int> arr)
{
    for (int i=0; i<arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void heapify(vector<int> arr, int root, int size)
{
    int largest = root;
    int left = root*2;
    int right = root*2+1;

    if((left<size)&&(arr[left]>arr[root]))
    {
        largest = left;
    }
    if((right<size)&&(arr[right]>arr[largest]))
    {
        largest = right;
    }
    if(largest!=root)
    {
        swap(&largest, &root);
        heapify(arr,largest,arr.size());
    }
}

void heapsort(vector<int> arr)
{
    int n = arr.size();
    for(int i=n/2; i>=0; i--)
    {
        heapify(arr, i, arr.size());
    }

    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr,0,i);
    }
}

int main() {
  vector<int> arr = {12, 11, 13, 5, 6, 7};
  heapsort(arr);

  cout << "Sorted array is \n";
  printArray(arr);
  getchar();
	return 0;
}
