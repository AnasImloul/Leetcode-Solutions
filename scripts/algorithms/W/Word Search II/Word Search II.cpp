// Runtime: 764 ms (Top 70.20%) | Memory: 13.2 MB (Top 40.34%)
class Solution {
public:
    vector<string> result;

    struct Trie {
        Trie *child[26];
        bool isEndOfWord;
        string str;

        Trie(){
            isEndOfWord = false;
            str = "";
            for(int i=0; i<26; i++)
                child[i] = NULL;
        }
    };

    Trie *root = new Trie();

    void insert(string &word) {

        Trie *curr = root;

        for(int i=0; i<word.size(); i++) {
            int index = word[i]-'a';

            if(!curr->child[index])
                curr->child[index] = new Trie();

            curr = curr->child[index];
        }

        curr->isEndOfWord = true;
        curr->str = word;
    }

    void trieSearchDFS(vector<vector<char>>& board, Trie *curr, int i, int j, int row, int col) {

        if(i<0 || i>row || j<0 || j>col || board[i][j] == '@')
            return;

        //int index = board[i][j]-'a';
        curr = curr->child[board[i][j]-'a'];

        if(curr == NULL)
            return;

        if(curr->isEndOfWord){
            result.push_back(curr->str);
            curr->isEndOfWord = false;
        }

        char ch = board[i][j];
        board[i][j] = '@';

        if(i-1>=0)
            trieSearchDFS(board,curr,i-1,j,row,col);
        if(j+1<col)
            trieSearchDFS(board,curr,i,j+1,row,col);
        if(i+1<row)
            trieSearchDFS(board,curr,i+1,j,row,col);
        if(j-1>=0)
            trieSearchDFS(board,curr,i,j-1,row,col);

        board[i][j] = ch;

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row = board.size();
        int col = board[0].size();

        for(int i=0; i<words.size(); i++)
            insert(words[i]);

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                trieSearchDFS(board,root,i,j,row,col);
            }
        }
       return result;
    }
};