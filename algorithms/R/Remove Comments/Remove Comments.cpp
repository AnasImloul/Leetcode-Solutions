class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool commentStart = false;
        vector<string> res;
        
        bool multiComment = false; // are we having a multi-line comment?
        for (string &eachS : source) {
            if (!multiComment) {
                res.emplace_back();
            }
            for (int i = 0; i < eachS.size(); i++) {
                if (!multiComment && eachS[i] == '/') {
                    i++;
                    if (eachS[i] == '/') {
                        break;
                    } else if (eachS[i] == '*') {
                        multiComment = true;
                    } else {
                        res.back() += '/';
                        res.back() += eachS[i];
                    }
                } else if (multiComment && eachS[i] == '*') {
                    if (i + 1 < eachS.size() && eachS[i + 1] == '/') {
                        i++;
                        multiComment = false;
                    }
                } else {
                    if (!multiComment) {
                        res.back() += eachS[i];
                    }
                }
            }
            if (!multiComment && res.back().empty()) {
                res.pop_back();
            } 
        }
        return res;
    }
};
