class TrieNode{
public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(){
        isEnd = false;
        children = vector<TrieNode*>(26, NULL);
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string& word, bool& isSuffix){
        auto cur = root;
        for(int i=0; i<word.size(); i++){
            int index = word[i] - 'a';
			
			//If new node is needed to be inserted for this word, then this word can't be suffix of some other word.
            if(cur->children[index] == NULL){
                isSuffix = false;
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur -> isEnd= true;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() > b.size();
        });
        
        int res = 0;
        Trie* trie = new Trie();

		for(auto word: words){
            reverse(word.begin(), word.end());
            bool wordIsSuffix = true;
            trie->insert(word, wordIsSuffix);
            // If word is not suffix of some other word, it needs to be added separately
            if(!wordIsSuffix) res += word.size()+1; //+1 for '#'
        }
        return res;
    }
};
