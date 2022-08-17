class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<int> u, l;
        vector<vector<int>> ans;
        
        for(int i : colsum){
            if(i == 2){
                u.push_back(1);
                l.push_back(1);
                upper--;
                lower--;
            }
            else if(i == 0) u.push_back(0), l.push_back(0);
            
            else if(i == 1){
                if(upper >= lower){
                    u.push_back(1);
                    l.push_back(0);
                    upper--;
                }
                else{
                    u.push_back(0);
                    l.push_back(1);
                    lower--;
                }
            }
        }
        if(upper == 0 && lower == 0){
            ans.push_back(u);
            ans.push_back(l);
        }
        return ans;
    }
};
