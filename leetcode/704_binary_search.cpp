#include<iostream>
#include<vector>

using namespace std;

int search_recursive(int arr[], int low, int high, int key){

  int pos;
  int mid = (low+high)/2;
  if(low > high) {
    pos = -1;
  } else if(arr[mid] == key) {
    pos = mid;
  } else if(key <= arr[mid]) {
      int newhigh = mid-1;
      pos = search_recursive(arr, low, newhigh, key);
  } else {
      int newlow = mid+1;
      pos = search_recursive(arr, newlow, high, key);
  }

  return pos;

}

int search_nonrecursive(int arr[], int low, int high, int key) {
  int pos = -1;
  int mid = 0;
  while(low <= high){
    mid = (low + high)/2;
    if(arr[mid] == key){
      pos = mid;
      break;
    } else if(key <= arr[mid]) {
      high = mid-1;
    } else {
      low = mid+1;
    }
  }
  return pos;
}

int search_nonrec_cpp(vector<int>& nums, int target){
  int pos = -1;
  int low = 0;
  int mid = 0;
  int high = nums.size()-1;
  while(low<=high){
    mid = (low+high)/2;
    if(nums[mid] == target) {
      pos = mid;
      break;
    } else if(target < nums[mid]){
      high = mid-1;
    } else {
      low = mid+1;
    }
  }
  return pos;
}

int main(){
  int low = 0;
  int high = 9;
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int key = 23;
  cout << search_nonrecursive(arr, low, high, key) << endl;
  cout << search_nonrecursive(arr, low, high, 100) << endl;
  return 0;
}
