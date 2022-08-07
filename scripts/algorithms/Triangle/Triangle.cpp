class Solution {
public:
    
    
    int travel(vector<vector<int>>& tr , int lvl , int ind) {
        
        if(ind >= tr[lvl].size()) // To check if we are going out of bound 
            return INT_MAX;
        
        if(lvl == tr.size() - 1) { // Return if we are on last line
            return tr[lvl][ind];
        }
        
        int s = travel(tr , lvl + 1, ind ); // Go South
        int se = travel(tr , lvl + 1 , ind + 1); // Go South East 
        
		// Return the minimum of south and south east + cost of the index we are currently at.
		
        return min(s , se) + tr[lvl][ind]; 
        
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        return travel(triangle , 0 , 0);
    }
};
