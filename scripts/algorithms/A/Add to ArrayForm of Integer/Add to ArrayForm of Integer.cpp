// Runtime: 12 ms (Top 95.91%) | Memory: 31.20 MB (Top 5.95%)

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int n = num.size();
        int carry = 0, i = n-1;
        while (k > 0 || i >= 0 || carry > 0) {
            int sum = carry;
            if (k > 0) {
                int remainder = k % 10;
                sum += remainder;
                k = k / 10;
            }
            if (i >= 0) {
                sum += num[i];
                i--;
            }
            carry = sum / 10;
            ans.push_back(sum % 10);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
