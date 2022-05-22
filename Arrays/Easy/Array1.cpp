// Problem Link - https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0],fast=nums[nums[0]];  // 0 is not gonna be a part of cycle
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]]; // faster than slow by 1
        }
        
        // Now we get the first intersection 
        // Now we start moving from 0th position in forward direction
        // and also from the first intersection point in forward direction 
        // and the second intersection that we get will be the answer
        // This floyd's algorithm
        
        int second_iter=0;
        while(second_iter!=fast){
            second_iter=nums[second_iter];
            fast=nums[fast];
        }
        return fast;
    }
};