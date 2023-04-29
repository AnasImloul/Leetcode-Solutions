class Solution {
public:
    string baseNeg2(int n) {
        if(n == 0) 
            return "0";
        string ans = "";
        while(n != 0)
        {
            int rem = n % -2;
            if(rem < 0)
            {
                rem += 2;
                n--;
            }
            ans = to_string(rem) + ans;
            n = n / -2;
        }
        return ans;
    }
};