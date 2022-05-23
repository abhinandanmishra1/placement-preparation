class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int minimumElement=INT_MAX;
        for(auto x:nums){
            minimumElement=min(minimumElement,x);
        }
        
        for(auto x:nums){
            ans+=x-minimumElement;
        }
        return ans;
    }
};