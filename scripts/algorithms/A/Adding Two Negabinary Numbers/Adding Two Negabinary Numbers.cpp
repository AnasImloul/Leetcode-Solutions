// Runtime: 11 ms (Top 68.21%) | Memory: 19.6 MB (Top 18.50%)

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {

        int i = arr1.size()-1;
        int j = arr2.size()-1;

        // prestore bits and carry for different sum values
        vector<int>bits = {0,1,0,1,0,1};
        vector<int>carries = {1,1,0,0,-1,-1};

        vector<int>res;

        int sum;
        int carry = 0;

        // perform binary addition using sum and prestored bit and carry values
        while(i>=0 || j>=0 || carry)
        {
            sum = carry + (i>=0 ? arr1[i--] : 0) + (j>=0 ? arr2[j--] : 0);

            carry = carries[sum+2];

            res.push_back(bits[sum+2]);
        }

        // remove leading zeroes
        while(res.size() > 1 && res.back()==0)res.pop_back();

        reverse(res.begin(),res.end());

        return res;
    }
};