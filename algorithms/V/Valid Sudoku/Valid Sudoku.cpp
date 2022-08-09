class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n = board.size();
        
        for(int i=0;i<n;i++){
            unordered_map<char,int>m;
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(m.find(board[i][j])!=m.end()){
                    return false;
                }
                else{
                    m[board[i][j]]++;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            unordered_map<char,int>m;
            for(int j=0;j<n;j++){
                
                if(board[j][i]=='.'){
                    continue;
                }
                
                if(m.find(board[j][i])!=m.end()){
                    return false;
                }
                else{
                    m[board[j][i]]++;
                }
            }
        }
        
        for(int i=0;i<n;i+=3){
            for(int j=0;j<n;j+=3){
                
                unordered_map<char,int>m;
                for(int k=i;k<=i+2;k++){
                    for(int p=j;p<=j+2;p++){
                        
                        if(board[k][p]=='.'){
                            continue;
                        }
                        
                        if(m.find(board[k][p])!=m.end()){
                            return false;
                        }
                        else{
                            m[board[k][p]]++;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
