class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int c1 = 0, c2 = 0, num1 = -1, num2 = -1;
        for(int i : nums){
            if(i == num1){
                c1++;
            }
            else if(i == num2){
                c2++;
            }
            else if(c1 == 0){
                num1 = i;
                c1++;
            }
            else if(c2 == 0){
                num2 = i;
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        vector<int> ans;
        c1 = 0, c2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == num1){
                c1++;
            }
            else if(nums[i] == num2){
                c2++;
            }
        }
        
        
        if(c1 > nums.size()/3){
            ans.push_back(num1);
        }
        
        if(c2 > nums.size()/3){
            ans.push_back(num2);    
        }
        return ans;
    }
};
