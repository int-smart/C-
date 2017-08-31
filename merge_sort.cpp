#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> arr)
{
  for (int i=0; i<arr.size(); ++i)
      cout << arr[i] << " ";
  cout << "\n";
}

vector<int> mergesort(vector<int> arr, int start, int stop) {
  int mid = start+(stop-start)/2;
  vector<int> left, right, output;
  left = mergesort(arr, start, mid);
  right = mergesort(arr, mid+1, stop);
  output = merge(left, right);
  return output;
}

void merge(vector<int> left, vector<int> right)
{
  int i, j;
  while((i<left.size())&&(j<right.size()))
  {

  }
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {12, 11, 13, 5, 6, 7};
  vector<int> sorted;
  sorted = mergesort(arr, 0, arr.size()-1);

  cout << "Sorted array is \n";
  printArray(sorted);
  getchar();
  return 0;
}
