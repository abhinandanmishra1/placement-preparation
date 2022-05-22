class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=1;
        int previousMinimum=prices[0];
        int ans=0;
        while(i<prices.size()){
            if(prices[i]>prices[i-1]) i++;
            else{
                ans+=prices[i-1]-previousMinimum;
                previousMinimum=prices[i];
                i++;
            }
        }
        ans+=prices[i-1]-previousMinimum;
        return ans;
    }
};


// More simpler way to do it 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int i=0;
        while(i<prices.size()-1){
            if(prices[i]<prices[i+1]){
                profit+=prices[i+1]-prices[i];
            }
            i++;
        }
        return profit;
    }
};