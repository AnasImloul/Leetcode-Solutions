class Solution {
    
    unordered_map<string, int> next_index_;
    
    bool contain(const string& fn) {
        return next_index_.find(fn) != next_index_.end();
    }
    
    string get_name(string fn) {
        if (!contain(fn)) {
            next_index_.insert({fn, 1});
            return fn;
        }
        
        int idx = next_index_[fn];
        auto cur = fn;
        while (contain(cur)) {
            next_index_.insert({cur, 1});
            cur = fn + "(" + to_string(idx) + ")";
            ++idx;
        }
        next_index_.insert({cur, 1});
        next_index_[fn] = idx;
        return cur;
    }
    
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> res;
        for (auto& n : names) {
            res.push_back(get_name(n));
        }
        
        return res;
    }
};
