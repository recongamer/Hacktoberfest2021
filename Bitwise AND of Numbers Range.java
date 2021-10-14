/*
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
Example 1:
Input: left = 5, right = 7
Output: 4
Example 2:
Input: left = 0, right = 0
Output: 0
Example 3:
Input: left = 1, right = 2147483647
Output: 0
 
Constraints:
0 <= left <= right <= 231 - 1
*/


//Solution:
class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int bitsLeft = 0;
        int bitsRight = 0;
        int l = left;
        int r = right;
        if (left == right) 
            return left;
        while(left > 1) {
            left = left/2;
            bitsLeft++;
        } 
        while(right > 1) {
            right = right/2;
            bitsRight++;
        }
        
        long result = l;
        if (bitsRight == bitsLeft &&  bitsRight != 0) {
            for(long i = l+1; i<= r; i++) 
                result = result & i;
            return (int)result;
        }
        else 
            return 0;
    
    }
}
