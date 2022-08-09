class Solution {
public:
	bool flag=false;
	void exist(int k,int i ,int j,string& word,vector<vector<char>>& board,vector<vector<int>>& vis,int n,int m){
		if(k==word.size()){  
			flag=true;
			return;
		}   
//      Down   
		if(!flag && i+1<m && !vis[i+1][j] && board[i+1][j]==word[k]){
			vis[i][j]=1;
			exist(k+1,i+1,j,word,board,vis,n,m);
			vis[i][j]=0;
		}
//      Left
		if(!flag && j-1>=0 && !vis[i][j-1] && board[i][j-1]==word[k]){
			vis[i][j]=1;
			exist(k+1,i,j-1,word,board,vis,n,m);
			vis[i][j]=0;
		}
//      Right
		if(!flag && j+1<n && !vis[i][j+1] && board[i][j+1]==word[k]){
			vis[i][j]=1;
			exist(k+1,i,j+1,word,board,vis,n,m);
			vis[i][j]=0;
		}
//      up
		if(!flag && i-1>=0 && !vis[i-1][j] && board[i-1][j]==word[k]){
			vis[i][j]=1;
			exist(k+1,i-1,j,word,board,vis,n,m);
			vis[i][j]=0;
		}
	}

	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();
		vector<vector<int>> vis(m,vector<int>(n,0));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(word[0]==board[i][j]) exist(1,i,j,word,board,vis,n,m);
				if(flag) return flag;
			}
		}
		return false;
	}
};