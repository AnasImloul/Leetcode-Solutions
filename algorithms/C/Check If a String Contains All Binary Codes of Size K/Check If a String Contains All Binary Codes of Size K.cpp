class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k)
        {
            return false;
        }
        unordered_set<string> binary_codes;
        for (int i = 0; i < s.size()-k+1; i++)
        {
            string str = s.substr(i, k);
            binary_codes.insert(str);
            if (binary_codes.size() == (int)pow(2, k))
            {
                return true;
            }
        }
        return false;
    }
};