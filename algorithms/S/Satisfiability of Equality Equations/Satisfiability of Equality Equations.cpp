class Solution {
public:    
    bool equationsPossible(vector<string>& equations) {
        
        unordered_map<char,set<char>> equalGraph;       //O(26*26)
        unordered_map<char,set<char>> unEqualGraph;     //O(26*26)
        
        //build graph:
        for(auto eq: equations){
            char x = eq[0], y = eq[3];
            if(eq[1] == '='){
                equalGraph[x].insert(y);
                equalGraph[y].insert(x);
            } 
            else{
                unEqualGraph[x].insert(y);
                unEqualGraph[y].insert(x);
            }
        }
        
        //for each node in inequality, check if they are reachable from equality:
        for(auto it: unEqualGraph){
            char node = it.first;
            set<char> nbrs = it.second;         //all nbrs that should be unequal
            if(nbrs.size() == 0) continue;
                        
            unordered_map<char,bool> seen;  
            bool temp = dfs(node, seen, equalGraph, nbrs);
            if(temp) return false;          //if any nbr found in equality, return false
        }
        
        return true;
        //TC, SC: O(N*N) + O(26*26)
    }
    
    
     bool dfs(char curNode, unordered_map<char,bool> &seen, unordered_map<char,set<char>> &equalGraph, set<char> &nbrs){
        
        seen[curNode] = true;
        if(nbrs.find(curNode) != nbrs.end()) return true;
        
        for(auto nextNode: equalGraph[curNode]){
            if(seen.find(nextNode) == seen.end()){
                bool temp = dfs(nextNode, seen, equalGraph, nbrs);
                if(temp) return true;
            }
        }
        
        return false;
    }
    
};
