class Solution {
public:
    string decodeAtIndex(string s, int k) {
        k--;
        struct op { string s; size_t mult; size_t total; };
        vector<op> v;
        size_t total = 0;
        for (auto c : s) {
            if (isalpha(c)) {
                if (v.empty() || v.back().mult > 1)
                    v.push_back({"", 1, total});
                v.back().s += c;
                v.back().total = ++total;
            } else {
                size_t m = c-'0';
                v.back().mult *= m;
                v.back().total = total *= m;
            }
            if (total > k) break;
        }
        while (!v.empty()) {
            auto [s, mult, total] = v.back();
            v.pop_back();
            size_t part = total / mult;
            k %= part;
            if (size_t i = k-part+s.size(); i < s.size())
                return {s[i]};
        }
        return "#";
    }
};
