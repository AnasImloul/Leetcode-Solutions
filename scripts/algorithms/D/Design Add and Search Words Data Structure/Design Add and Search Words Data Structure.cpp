// Runtime: 2662 ms (Top 14.83%) | Memory: 623.6 MB (Top 10.10%)
class WordDictionary {
public:
    struct tr {
        bool isword;
        vector<tr*> next;
        tr() {
            next.resize(26, NULL);
            isword = false;
        }
    };

    tr *root;
    WordDictionary() {
        root = new tr();
    }

    void addWord(string word) {
        tr *cur = root;

        for(auto c: word) {
            if(cur->next[c-'a'] == NULL) {
                cur->next[c-'a'] = new tr();
            }
            cur = cur->next[c-'a'];
        }

        cur->isword = true;
    }

    bool dfs(string& word, int i, tr* cur) {
        if(!cur ){
            return false;
        }

        if(i == word.size()) {
            return cur->isword;
        }

        for (; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto it: cur->next) {
                    if(dfs(word, i+1, it)) {
                        return true;
                    }
                }
                return false;
            }
            else {
                if(cur->next[c-'a'] == NULL) {
                    return false;
                }
                cur = cur->next[c-'a'];
            }
        }

        return cur->isword;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */