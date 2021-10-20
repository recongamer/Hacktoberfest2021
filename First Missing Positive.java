/*
Given an unsorted integer array nums, return the smallest missing positive integer.
You must implement an algorithm that runs in O(n) time and uses constant extra space.
 
Example 1:
Input: nums = [1,2,0]
Output: 3
Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
 
Constraints:
1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
*/

//solution:
class Solution {
    public int firstMissingPositive(int[] nums) {
        cyclicSort(nums);
        for(int i = 0 ; i < nums.length;i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }               
        return nums.length + 1;
    }
    public void cyclicSort(int[] arr){
        int i = 0;
        while(i < arr.length){
            if(arr[i] > 0 && arr[i] <= arr.length && arr[i] != arr[arr[i] - 1]){
                    swapArray(arr,i,arr[i]-1);
            }else {
                i++;
            }
        }
    }
    public void swapArray(int[] arr,int first,int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }

}
