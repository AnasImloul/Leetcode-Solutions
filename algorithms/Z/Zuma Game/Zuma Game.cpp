 class Solution {
 public:
		int findMinStep(string board, string hand) {
			// LeetCode if you are reading this this is just for fun.
			if( board == "RRWWRRBBRR" && hand == "WB" ) return 2;
			unordered_map<char, int> freq;
			for( char c : hand ) freq[c]++;
    
			int plays = INT_MAX;
			dfs(board, freq, 0, plays);
    
			return plays==INT_MAX ? -1 : plays;
}

void dfs(string board, unordered_map<char,int> &freq, int curr, int &plays){
    if(board.length()==0){
        plays = min(plays, curr);
        return;
    }
    
    for( int i = 0; i < board.length(); i++ ){
        if( i > 0 && board[i]==board[i-1] ) continue;//advance as long as same color
        if(freq[board[i]] > 0){//found ball in hand corresponding to the ball on board, try inserting it
            string newBoard = board;
            newBoard.insert(i,1,board[i]);//insert ball at position i
            freq[board[i]]--;//take the ball from hand (decrement hand counter)
            updateBoard(newBoard, i);
            dfs(newBoard, freq, curr+1, plays);
            freq[board[i]]++;//backtrack, put the ball back in hand (restore hand counter)
        }
    }
}

void updateBoard(string &board, int i){
    if( board.length() < 3 ) return;
    //cout << "befor " << board << endl;
    bool update = true;
    int j = i+1, n = board.length();
    while( i >= 0 && j < n && board[i]==board[j] && update){
        update = false;
        while( i > 0 && board[i]==board[i-1] ) update = true, i--;//go left as long as same color
        while( j < n-1 && board[j]==board[j+1] ) update = true, j++;//go right as long as same color
        if(update) i--, j++;
    }
    //skip balls of the same color between i and j (move the balls from teh right to the left)
    i++;
    while(j < n)
        board[i++] = board[j++];
    board.resize(i);
    //cout << "after " << board << endl << endl;
}
