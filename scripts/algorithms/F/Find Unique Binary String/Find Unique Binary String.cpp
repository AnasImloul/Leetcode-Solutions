class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> s;
        for (auto num : nums) s.insert(stoi(num, 0, 2));
        int res = 0;
        while (++res) {
            if (!s.count(res)) return bitset<16>(res).to_string().substr(16-nums.size());
        }
        return "";
    }
};
