class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            int x=abs(nums[i])-1;
            
            if(nums[x]<0){
                // If the number is negative that means it has been visited
                // Hence it is repeating
                ans.push_back(x+1); // x+1 means the repeated number
            }else{
                // If the number is positive that means it has not been visited
                // Mark it as negative
                nums[x]=-nums[x];
            }
        }
        return ans;
    }
};