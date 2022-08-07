class Trie {
public:
    struct tr {
        bool isword;
        vector<tr*> next;
        tr() {
            next.resize(26, NULL); // one pointer for each character
            isword = false;
        }
    };
    
    tr *root;
    Trie() {
        root = new tr();
    }
    
    void insert(string word) {
        tr *cur = root;
        
        for(auto c: word) {
			// if pointer to char doesn't exist create one
            if(cur->next[c-'a'] == NULL) {
                cur->next[c-'a'] = new tr();
            }
            cur = cur->next[c-'a'];
        }
        
		// set as end or valid word
        cur->isword = true;
    }
    
    bool search(string word) {
        tr *cur = root;
        
        for(auto c: word) {
			// if pointer to char doesn't exist then word is not present
            if(cur->next[c-'a'] == NULL) {
                return false;
            }
            
            cur = cur->next[c-'a'];
        }
        
		// check if it is prefix or a word
        if(cur->isword){
            return true;
        }
        return false;
    }
    
	// similar to search 
	// here we don't check if it is end or not
    bool startsWith(string prefix) {
        tr *cur = root;
        
        for(auto c: prefix) {
            if(cur->next[c-'a'] == NULL) {
                return false;
            }
            
            cur = cur->next[c-'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
