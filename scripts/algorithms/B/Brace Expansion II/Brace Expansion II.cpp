// Runtime: 7 ms (Top 85.26%) | Memory: 10.50 MB (Top 92.63%)

class Solution {
public:
    void getUnion(vector<string>& a, const vector<string>& b) {
        if (!a.size()) {
            a = b;
            return;
        }
        for (const auto& str_b: b) {
            bool found = false;
            for (const auto& str_a: a) {
                if (str_a == str_b) {
                    found = true;
                    break;
                }
            }
            if (!found) a.push_back(str_b);
        }
    }
    void getComb(vector<string>& a, const vector<string>& b) {
        if (!a.size()) {
            a = b;
            return;
        }
        vector<string> tmp;
        for (const auto& str_a: a) {
            for (const auto& str_b: b) {
                tmp.push_back(str_a + str_b);
            }
        }
        a = tmp;
    }
    vector<string> braceExpansionII(string expression) {
        if (expression.size() == 0) return {};
        if (expression.size() == 1) return {expression};
        int n = expression.size();
        vector<string> ans;
        vector<string> processing_str;
        int in_brace = 0;
        string partial_str{};

        for (int i = 0; i < n; ++ i) {
            if (expression[i] == '{') {
                if (in_brace) partial_str += expression[i];
                in_brace ++;
            } else if (expression[i] == '}') {
                in_brace --;
                if (in_brace) partial_str += expression[i];
                if (!in_brace) {
                    getComb(processing_str, braceExpansionII(partial_str));
                    partial_str.clear();
                }
            } else if (in_brace == 0 && expression[i] == ',') {
                getUnion(ans, processing_str);
                processing_str.clear();
                partial_str.clear();
            } else if (in_brace == 0) { 
                std::string tmp = "";
                while (i < n && expression[i] >= 'a' && expression[i] <= 'z') 
                    tmp += expression[i++];
                -- i;
                getComb(processing_str, {tmp});
            } else {
                partial_str += expression[i];
            }
        }
        getUnion(ans, processing_str);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
