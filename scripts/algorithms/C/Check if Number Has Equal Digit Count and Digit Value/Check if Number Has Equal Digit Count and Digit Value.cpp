class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int,int> mpp;
        int n= num.length();
        for(auto it:num){
            int x = it - '0';
            mpp[x]++; // Store the frequency of the char as a number
        }
        for(int i=0;i<n;i++){
            int x = num[i] - '0'; // get the char as number
 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;if(mpp[i] != x) // f the number is not equal to its frequency we return false
                return false;
        }
        return true;
    }
};

