class Solution {
public:
    vector<int> ans;
    
    void bin(int lo, int hi, int num) {
        if(lo == hi) {
            ans[lo] = num;
            return;
        }
        int mid = (lo + hi) / 2;
        if(ans[mid] < num) bin(mid + 1, hi, num);
        else bin(lo, mid, num);
    }
    
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> idx;
        for(int i = 0; i < target.size(); i++) {
            idx[target[i]] = i;
        }
        
        for(int i = 0; i < arr.size(); i++) {
            if(idx.find(arr[i]) == idx.end()) continue;
            int num = idx[arr[i]];
            if(ans.size() == 0 || num > ans.back()) {
                ans.push_back(num);
            }
            else {
                bin(0, ans.size() - 1, num);
            }
        }
        
        return (target.size() - ans.size());
    }
};
