class Solution {
public:

    using ll = long long;

    int countLen(int n) {
        int cnt = 0;
        while(n) {
            cnt++;
            n /= 10;
        }
        return cnt;
    }

    vector<int>getDigits(int n) {
        vector<int>digits;
        while(n) {
            digits.push_back(n % 10);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }


    int solve(int idx, bool flag, vector<int>&digits, vector<int>&number) {
        if(!flag) {
            int res = 1;
            for(int i = idx; i<number.size(); i++) {
                res *= digits.size();
            }
            return res;
        }


        if(idx >= number.size()) return 1;

        int curr = 0;

        for(int dig: digits) {
            if(dig < number[idx]) {
                curr += solve(idx + 1, false, digits, number);
            } else if(dig == number[idx]) {
                curr += solve(idx + 1, true, digits, number);
            } else break;
        }

        return curr;
    }


    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int len = countLen(n);
        vector<int>nums;
        for(string str: digits) {
            nums.push_back(stoi(str));
        }
        sort(nums.begin(), nums.end());
        ll res = 0;
        
        
        for(int i = 1; i<len; i++) {
            int curr = 1;
            bool flag = false;
            for(int j = 0; j<i; j++) {
                flag = true;
                curr *= (int)digits.size();
            }
            if(flag)
                res += curr;
        }

        vector<int>number = getDigits(n);
        
        res += solve(0, true, nums, number);

        return res;

    }
};

