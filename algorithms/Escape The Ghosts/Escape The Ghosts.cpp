class Solution {
public:
    
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int minimumstepsreqbyplayer = abs(target[0]) + abs(target[1]);
        int minimumstepsreqbyanyghost = INT_MAX;
        
        for(auto x: ghosts){
            minimumstepsreqbyanyghost = min(minimumstepsreqbyanyghost, abs(x[0]-target[0]) + abs(x[1]-target[1]));
        }
        
        return minimumstepsreqbyplayer<minimumstepsreqbyanyghost;
    }
};
