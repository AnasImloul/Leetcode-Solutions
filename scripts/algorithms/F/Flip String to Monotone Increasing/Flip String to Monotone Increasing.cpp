// Runtime: 46 ms (Top 47.95%) | Memory: 20.1 MB (Top 15.69%)
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        //assume start making 1 from i th index
        // what number of 0s we need to flip at right side
        // what number of 1s we need to flip at left side
        // for this maintain prefix and suffix

        int n = s.size();
        vector<int> noOfZerosToRight(n,0); // R to L
        vector<int> noOfOnesToLeft(n,0); // L to R

        if(s[0] == '1') noOfOnesToLeft[0] = 1;
        for(int i=1;i<n;i++){
            if(s[i] == '1') noOfOnesToLeft[i] = noOfOnesToLeft[i-1] + 1;
            else noOfOnesToLeft[i] = noOfOnesToLeft[i-1];
        }

        if(s[n-1] == '0') noOfZerosToRight[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            if(s[i] == '0') noOfZerosToRight[i] = noOfZerosToRight[i+1] + 1;
            else noOfZerosToRight[i] = noOfZerosToRight[i+1];
        }

        // starting treating i as partition of 0 and 1:
        // 0 at the lefts and 1 at the rights including i:
        int ans = 1e9;
        for(int i=0;i<n;i++){
            int leftFlips = 0; //when we want all 1s
            int rightFlips = noOfZerosToRight[i];

            if(i-1 >= 0) leftFlips = noOfOnesToLeft[i-1];
            ans = min(ans, (leftFlips + rightFlips));
        }

        ans = min(ans, noOfOnesToLeft.back() + 0); //when want all 0s
        return ans;
    }
    //O(N) + O(N)
};