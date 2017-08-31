#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*void printArray(vector<int> arr)
{
    for (int i=0; i<arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}*/

vector<int> countingsort(vector<int> arr)
{
  auto max_item = max_element(arr.begin(), arr.end());
  int max_value = *max_item;
  vector<int> count(max_value+1,0);
  vector<int> output(arr.size());
  for (auto i : arr)
  {
    count[i]++;
  }
  for(int i=1; i<max_value+1; i++)
  {
    count[i] += count[i-1];
  }
  for(int i=0; i<arr.size(); i++)
  {
    output[count[arr[i]]-1] = arr[i];
    count[arr[i]]--;
  }
  return output;
}

/*int main(int argc, char const *argv[]) {
  vector<int> arr = {12, 12, 11, 100, 13, 5, 6, 7};
  vector<int> output;
  output = countingsort(arr);

  cout << "Sorted array is \n";
  printArray(output);
  getchar();
	return 0;
}
*/
