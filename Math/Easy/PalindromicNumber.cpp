class Solution {
public:
    bool isPalindrome(int x) {
        long int t=0;
        if(x<0) return false;
        int l=x;
        while(l){
            t=t*10+l%10;
            l/=10;
        }
        return x==t;
    }
};