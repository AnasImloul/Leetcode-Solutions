
class Solution {
public:
    
    vector<int> get_kmp_table(const string &s) {
        vector<int> table(s.size());
        int i=0; int j=-1;
        table[0] = -1;
        while (i < s.size()) {
            if (j == -1 || s[i] == s[j]) {
                i++;
                j++;
                table[i] = j;
            }
            else {
                j = table[j];
            }
        }
        return table;
    }
    
    bool validate_table(const vector<int>& table) {
        int idx = table.size() - 1;
        while (idx >= 0 && table[idx] > 0) {
            idx--;
        }
        if (idx <= 0) return false;
        int substr_len = idx;
        if (table.size() % substr_len != 0) return false;
        idx = idx + 1; // the first nonzero element in the string
        while (idx < table.size()-1) {
            if (table[idx] != table[idx+1]-1) return false;
            idx++;
        }
        return true;
    }
    
    bool repeatedSubstringPattern(string s) {
        if (s.size() <= 1) return true;
        
        auto table1 = get_kmp_table(s);
        string ss = s;
        reverse(ss.begin(), ss.end());
        auto table2 = get_kmp_table(ss);
        
        return (validate_table(table1) && validate_table(table2));
        
    }
};

