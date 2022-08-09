class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end()); 
        
        vector<int> ans; 
        while (n--) {
            int diff = sums[1] - sums[0]; 
            unordered_map<int, int> freq; 
            vector<int> ss0, ss1; 
            bool on = false; 
            for (auto& x : sums) 
                if (!freq[x]) {
                    ss0.push_back(x); 
                    freq[x+diff]++; 
                    if (x == 0) on = true; 
                } else {
                    ss1.push_back(x); 
                    freq[x]--; 
                }
            if (on) {
                ans.push_back(diff); 
                sums = ss0; 
            } else {
                ans.push_back(-diff); 
                sums = ss1; 
            }
        }
        return ans; 
    }
};
