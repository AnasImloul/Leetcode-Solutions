class Solution {
public:
    vector<int> cumW;  
    Solution(vector<int>& w) {
        // initialising random seeder
        srand(time(NULL));
        // populating the cumulative weights vector
        cumW.resize(w.size());
        cumW[0] = w[0];
        for (int i = 1; i < w.size(); i++) cumW[i] = cumW[i - 1] + w[i];
    }
    
    int pickIndex() {
        return upper_bound(begin(cumW), end(cumW), rand() % cumW.back()) - begin(cumW);
    }
};