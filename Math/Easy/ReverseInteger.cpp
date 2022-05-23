class Solution {
public:
    
    int reverse(int x) {
        bool flag=x<0;
        long long int ans=0;
        x=abs(x);
        while(x){
            ans=ans*10+x%10;
            x/=10;
        }
        ans=flag?-1*ans:ans;
        if(ans>INT_MAX or ans<INT_MIN){
            return 0;
        }
        return ans;
        
    }
};