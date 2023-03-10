class Solution {
private:
   bool doable(unordered_map<char, int> &mp) {
        unordered_set<int> st;
        for (auto &[key, val] : mp) {
            if (val > 0) {
                st.insert(val);
            }
        }
        return st.size() == 1;
    }
public:
    bool equalFrequency(string &word) {
        unordered_map<char, int> mp;
        for (char &c : word) mp[c]++;
        for (auto &[key, val] : mp) {
            mp[key]--;
            if (doable(mp)) return true;
            mp[key]++;
        }
        return false;
    }
};