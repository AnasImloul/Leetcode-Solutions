class Solution {
public:
    void back_tracking(vector<string>& res, string cus, int lp, int rp, int idx) {
        if (!lp && !rp) {
            int invalid = 0;
            bool flag = true;
            for (int i = 0; i < cus.size(); i++) {
                if (cus[i] == '(')
                    invalid++;
                else if (cus[i] == ')') {
                    invalid--;
                    if (invalid < 0) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
                res.emplace_back(cus);
            return;
        }
        
        for (int i = idx; i < cus.size(); i++) {
            if (i != idx && cus[i] == cus[i - 1])
                continue;
            
            if (lp + rp > cus.size() - i)
                return;
            
            if (lp && cus[i] == '(')
                back_tracking(res, cus.substr(0, i) + cus.substr(i + 1), lp - 1, rp, i);
            
            if (rp && cus[i] == ')')
                back_tracking(res, cus.substr(0, i) + cus.substr(i + 1), lp, rp - 1, i);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int left_p = 0;
        int right_p = 0;
        for (auto& ch : s) {
            if (ch == '(')
                left_p++;
            else if (ch == ')') {
                if (left_p > 0)
                    left_p--;
                else
                    right_p++;
            }
        }
        vector<string> res;
        back_tracking(res, s, left_p, right_p, 0);
        return res;
    }
};
