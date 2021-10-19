
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for (int i=0; i<nums.size(); i++) {
            int v = nums[i];
            int c = target - v;
            if (map.find(c)!=map.end()) {
                return {i,map[c]};
            }
            else {
                map[v] = i;
            }
        }
        return {-1,-1};
    }
};
