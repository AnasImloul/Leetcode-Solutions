class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){        
            sort(stones.begin(), stones.end(), greater<int>());
            stones[1] = (stones[0]-stones[1]);
            stones.erase(stones.begin());
        }
        return stones[0];
    }
};
