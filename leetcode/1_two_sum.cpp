class Solution{
public:
  vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int>map;
    for(int i=0;i<nums.size();++i){
      auto node = map.find(target-nums[i]);
      if(node!=map.end()) return {node->second,i};
      map[nums[i]]=i;
    }
    return {};
  }
}
