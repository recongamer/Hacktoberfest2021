/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 
Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
 
Constraints:
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

//Solution:
class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int[] Leftmax = new int[n];
        int ll = 0;
        for(int i = 0;i<n;i++){
            Leftmax[i] = ll;
            ll = Math.max(ll,height[i]);
        }
        int[] Rightmax = new int[n];
        int rl = 0;
        for(int i = n-1; i>=0;i--){
            Rightmax[i] = rl;
            rl = Math.max(rl,height[i]);
        }
        
        int ans = 0;
        for(int i =0;i<n;i++){
            ans += Math.max(0,Math.min(Leftmax[i],Rightmax[i]) - height[i]);
        }
        
        return ans;
        
        
    }
}
