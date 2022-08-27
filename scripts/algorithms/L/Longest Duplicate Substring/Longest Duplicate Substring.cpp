// Runtime: 1100 ms (Top 92.69%) | Memory: 218.6 MB (Top 73.97%)
class Solution {
    using ull = unsigned long long;
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        vector<ull> power(n, 1);
        for (int i=1; i<n; i++) {
            power[i] = power[i-1] * 27;
        }
        return solve(s, power);
    }

    string solve(string& s, vector<ull>& power) {
        int low = 1, high = s.size();
        while(low <= high) {
            int mid = low + (high - low)/2;
            if (check(s, mid, power) != -1) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int start = check(s, low-1, power);
        if (start > 0) return s.substr(start, low-1);
        return "";
    }

    int check(string&s, int len, vector<ull>& power) {
        if (len <= 0) return -1;
        unordered_set<ull> st;
        ull curr_hash = 0;
        for(int i=0; i<len;i++) {
            curr_hash = curr_hash + power[len-i-1] * (s[i] - 'a');
        }
        st.insert(curr_hash);
        for(int i=len; i<s.size(); i++) {
            curr_hash = curr_hash - power[len-1] * (s[i-len] - 'a');
            curr_hash = curr_hash * 27;
            curr_hash = curr_hash + (s[i]-'a');
            if (st.count(curr_hash)) {
                return i-len+1;
            }
            st.insert(curr_hash);
        }
        return -1;
    }
};