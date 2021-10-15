https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int binary(vector<int>nums,int n,int low,int high,int target){
     //  int low=0,high=n-1;
      //  int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
           if(nums[mid]==target){
               return mid;
           }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1&&nums[0]!=target){
            return -1;
        }
        
        if(n==1&&nums[0]==target){
            return 0;
        }
     int low=0,high=n-1;
        int ans;
      //  int ans=-1;
        while(low<=high){
              int mid=low+(high-low)/2;
           if((mid>0&&nums[mid]<nums[mid-1])&&(mid<n-1&&nums[mid]<nums[mid+1])){
               ans=mid;
            break;
             //  return ans;
           }
            else if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
   //    return ans;
        int s=max(binary(nums,n,ans,n-1,target),binary(nums,n,0,ans,target));
       // binary(nums,n,target,)
        return s;
    }
};
