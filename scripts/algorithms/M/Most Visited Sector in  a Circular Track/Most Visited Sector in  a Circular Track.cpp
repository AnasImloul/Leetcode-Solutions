// Runtime: 0 ms (Top 100.0%) | Memory: 11.40 MB (Top 65.78%)

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector <int> ans;
        int size = rounds.size();
        
        if(rounds[0] <= rounds[size-1]) {
            for(int i=rounds[0]; i<= rounds[size-1]; i++) {
                ans.push_back(i);
            }
            return ans;
        }
        else {
            for(int i=1; i<= rounds[size-1]; i++) {
                ans.push_back(i);
            }   
            
            for(int i=rounds[0]; i<=n; i++) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
