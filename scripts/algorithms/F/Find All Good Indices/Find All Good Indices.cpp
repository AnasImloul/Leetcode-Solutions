class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        auto fall = falling(nums, k);
        auto rise = rising(nums, k);
        vector<int> res;
        for(int i = 0; i< nums.size(); ++i){
            if(fall[i] && rise[i])
                res.emplace_back(i);
        }
        return res;
    }

    vector<int> falling(vector<int>& num, int k){
        vector<int> res(num.size(),0);
        int falling_count = 1;
        for(int i = 1; i< num.size(); ++i){
            if(falling_count >= k) res[i] = 1;
            if(num[i]<=num[i-1]) falling_count++;
            else falling_count = 1;
        }
        return res;
    }
    vector<int> rising(vector<int>& num, int k){
        vector<int> res(num.size(),0);
        int rising_count = 1;
        for(int i = num.size()-2; i>=0; --i){
            if(rising_count >= k) res[i] = 1;
            if(num[i]<=num[i+1]) rising_count++;
            else rising_count = 1;
        }
        return res;
    }
};