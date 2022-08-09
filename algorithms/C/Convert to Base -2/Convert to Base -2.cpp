class Solution {
public:
    string baseNeg2(int n) {
        if(n==0) return "0";
        string result;
        while(n) {
            int c=n>>1;
            result += to_string(n-2*c);
            n = -c;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
