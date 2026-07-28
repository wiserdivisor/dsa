#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      double median;
      int loopend = (nums1.size() < nums2.size()) ? nums2.size() : nums1.size();
      for(int i=0; i<loopend; i++) {
        if(   )
      }
      return median;
    }
};

int main() {
  vector<int> v1 = {1,2};
  vector<int> v2 = {3,4};
  Solution sol;
  cout << "\nMedian: " << sol.findMedianSortedArrays(v1,v2);
  cout << endl;
  return 0;
}
