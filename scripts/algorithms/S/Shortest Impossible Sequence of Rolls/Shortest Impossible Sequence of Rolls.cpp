class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int len = 1;
        set<int> data ;
        
        for (int i = 0; i < rolls.size(); i++) {
            data.insert(rolls[i]);
            
            if (data.size() == k) {
                len++;
                data = set<int>();
            }
        }
        
        return len;
    }
};
