class Solution {
public:
    int result = 0;
    int n = 0;
    int maximumGood(vector<vector<int>>& statements) {
        n = statements.size();
        string cur = "";
        dfs(statements, cur, 0, 0);
        return result;
    }
    
    void dfs(vector<vector<int>>& statements, string& cur, int index, int goodPersonCount){
        if(index == n){
            //Check if cur is valid
            if(isValid(cur, statements)) result = max(goodPersonCount, result);
            return;
        }
        
        //Make current person a good person and call DFS
        cur.push_back('1');
        dfs(statements, cur, index+1, goodPersonCount+1);
        
        //Backtrack: Make current person a bad person and call DFS
        cur.back() = '0';
        dfs(statements, cur, index+1, goodPersonCount);
        
        cur.pop_back();
    }
    
    bool isValid(string& cur, vector<vector<int>>& statements){
        //isValid() will check if the statement of goodPerson (i) about person (j) i.e. statement[i][j], is contradictory to what we have in cur[j]
        
        //If it is contradictory, then in terms of question i is lying, and is not a goodPerson, so this is not a valid count.
        
        //If s[i][j] == 2, i.e. person i said nothing about j, then we can skip it.
        for(int i=0; i<n; i++){
            if(cur[i] == '1'){ //We only care about what good people say
                //Now we check what they said is in accordance with what we have in cur
                for(int j=0; j<n; j++){
                    if(statements[i][j] != 2 && statements[i][j] != cur[j] - '0') return false;
                }
            }
        }
        
        //All statements made by good person is in accordance with cur, so we have a valid count of good people
        return true;
    }
};
