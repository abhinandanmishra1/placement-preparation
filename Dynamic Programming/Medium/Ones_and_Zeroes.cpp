// Problem Link - https://leetcode.com/problems/ones-and-zeroes/

// Approach 
/*
 I have used 3 dimensional dp array to store the maximum answer for each 
 i zeroes, j ones and using k strings that is dp[i][j][k]

 for each string I am counting the number of zeroes and ones
 then running a loop for each i=0 to m zeroes, and j=0 to n ones
 
 for each i,j,k dp[i][j][k]=dp[i][j][k-1] is set intially 
  why?
  because jitne peechhe maximum answer aa chuka hai utna to rhega hi usse aage bdhne
  ke hi chances hain

  Aaage kab aayega??
  jab i>=zero and j>=one hoga uske baad
  dp[i][j][k] = max(dp[i][j][k], dp[i-zero][j-one][k-1] + 1);

  matlb agar current string is not include then answer is dp[i][j][k] but if it is included then
 answer should be maximum of current ans and dp[i-zero][j-one][k-1] + 1;

 +1 means cuurrent included string and dp[i-zero][j-one][k-1] matlb pichhle k-1 strings me i-zero
 zeroes aur j-one ones ke liye jo answer tha wo 
*/
class Solution {
public:  
    int findMaxForm(vector<string>& strs, int m, int n) {
        // ["10","0001","111001","1","0"]
        
        int size=strs.size();
        
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(size+1,0)));
        
        // this 3d vector signifies that -> dp[i][j][k]
        // How many strings can be made for maximum of i zeroes , j ones and using k strings
        int k=1;
        for(auto &str:strs){
            int zero=0,one=0;
            for(auto &ch:str){
                zero+=(ch=='0');
                one+=(ch=='1');
            }
            // whether this K should be included or not
            for(int i=0;i<=m;i++){
                for(int j=0;j<=n;j++){
                    if(i>=zero and j>=one)
                        dp[i][j][k]=max(dp[i][j][k-1],dp[i-zero][j-one][k-1]+1);
                    else
                        dp[i][j][k]=dp[i][j][k-1];
                }
            }
            k++;
        }
        return dp[m][n][size];
        
    }
};