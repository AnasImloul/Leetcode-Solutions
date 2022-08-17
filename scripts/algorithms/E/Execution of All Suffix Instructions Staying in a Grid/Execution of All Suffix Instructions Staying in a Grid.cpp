class Solution {
public:
    bool isValid(int row,int col,int n){
        return (row >= 0 && row < n && col >= 0 && col < n);
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int len = s.length();
        vector<int> ans;
        int row = startPos[0];
        int col = startPos[1];
        int currRow = row;
        int currCol = col;
        
        for(int i=0; i<len; i++){
            currRow = row;
            currCol = col;
            int currAns = 0;
            for(int j=i; j<len; j++){
                
                if(s[j] == 'R') currCol++;
                else if(s[j] == 'L') currCol--;
                else if(s[j] == 'U') currRow--;
                else currRow++;
                
                if(isValid(currRow,currCol,n))
                    currAns++;
                else
                    break;
            }
            ans.push_back(currAns);
        }
        return ans;
    }
};
