class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vector<bool> visited(n,false);
        queue<int> q;
        int res=0;
        unordered_set<int> st;
        for(int i=0;i<initialBoxes.size();i++){
            q.push(initialBoxes[i]);
            int box=initialBoxes[i];
            for(int i=0;i<keys[box].size();i++){
                st.insert(keys[box][i]);
            }
        }

        
        while(!q.empty()){
            int box=q.front();
            q.pop();
            res+=candies[box];
            
            for(int i=0;i<containedBoxes[box].size();i++){
                int curr_box=containedBoxes[box][i];
                if(st.find(curr_box)!=st.end() or status[box]==1){
                    q.push(curr_box);
                    for(int i=0;i<keys[curr_box].size();i++){
                        st.insert(keys[curr_box][i]);
                    }
                }
            }
        }
        
        return res;
    }
};
