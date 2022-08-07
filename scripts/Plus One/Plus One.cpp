class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size(), carry = 0, temp = 0;
        
        vector<int> arr;
        
        for(int i=len-1; i>=0; i--) { // traverse from back to front
            temp = digits[i] + carry;
            
            if(i == len-1) {
                temp++;
            }
            
            arr.push_back(temp % 10);
            carry = temp/10;
        }
        
        if(carry) {
            arr.push_back(carry);
        }
        
        reverse(arr.begin(), arr.end());
        return arr;
    }
};
