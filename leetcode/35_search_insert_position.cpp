#include <iostream>

using namespace std;

int insert_binser(int arr[], int length, int target) {
  int ans = -1;
  int low = 0;
  int pos = 0;
  int high = length-1;
  while(low<=high){
    pos = low+(high-low)/2;
    if(arr[pos] == target) {
      ans = pos;
      break;
    } else if(target < arr[pos]) {
      high = pos-1;
    } else {
      low = pos+1;
    }
  }
  if(ans==-1){
    ans = low;
  }
  return ans;
}

int main() {
  int arr[] = {1,3};
  cout << endl;
  cout << insert_binser(arr, 2, 12);
  cout << endl;
  return 0;
}
