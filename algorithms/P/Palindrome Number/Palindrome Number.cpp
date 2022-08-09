class Solution {
    long long convert(int x){
        //reversing can exceed the allowed INTEGER domain for 32-bit.
        long long ans=0;
        while(x>0){
            ans = ans*10+x%10;
            x=x/10;
        }
        return ans;
    }
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        //getting the reverse number and checking whether  reversed_number==original_number
        long long ans=convert(x);
        //typeCasting for Checking
        return ans==(long long)(x);
    }
};