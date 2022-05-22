// Problem Link - https://leetcode.com/problems/sort-colors/
// Used Ducth national algorithm to solve this problem

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0,k=nums.size()-1;
        while(j<=k){
            if(nums[j]==0){
                if(i==j){
                    i++;
                    j++;
                    continue;
                }
                swap(nums[i++],nums[j]);
            }else if(nums[j]==2){
                swap(nums[j],nums[k--]);
            }else{
                j++;
            }
        }
    }
};