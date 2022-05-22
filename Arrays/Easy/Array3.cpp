// Problem Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//Linear traverse O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ans=0;
        int i=0,j=1;
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }else{
                nums[i+1]=nums[j];
                i++;
                j++;
            }
        }
        return i+1;
    }
};

// Using upperbound 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        while(1){
            int k=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
            if(k==nums.size()) return i+1;
            nums[i+1]=nums[k];
            i++;
        }
        return 0;
    }
};
