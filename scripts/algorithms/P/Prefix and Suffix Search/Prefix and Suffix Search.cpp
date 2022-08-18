// Runtime: 1012 ms (Top 45.94%) | Memory: 281.2 MB (Top 5.04%)

class TrieNode{
public:
    vector<TrieNode*> children;
    vector<int> wordIndexList;

    TrieNode(){
        children = vector<TrieNode*>(26, NULL);
    }
};

class Trie{
public:
    //Root is a datamember of trie.
    TrieNode* root;

    //Constructor
    Trie(){
        //Initialize root.
        root = new TrieNode();
    }

    void insert(string& word, int wordIndex){
        auto cur = root;
        for(int i=0; i<word.size(); i++){
            int index = word[i] - 'a';
            if(!cur->children[index]) cur->children[index] = new TrieNode();
            cur = cur->children[index];
            cur->wordIndexList.push_back(wordIndex);
        }
    }

    vector<int> searchPrefOrSuff(string& str){
        auto cur = root;
        int n= str.size();
        for(int i=0; i<n; i++){
            int index = str[i] - 'a';
            if(cur->children[index] == NULL) return {};
            cur = cur -> children[index];
        }
        return cur->wordIndexList;
    }
};

class WordFilter {
public:
    Trie* prefixTrie = new Trie();
    Trie* suffixTrie = new Trie();
    unordered_map<string, int> mp;

    WordFilter(vector<string>& words) {
        int n= words.size();
        for(int i=0; i<n; i++) {
            string word = words[i];
            prefixTrie->insert(word, i);
            string rev = word;

            reverse(rev.begin(), rev.end());
            suffixTrie->insert(rev, i);
        }
    }

    int f(string pref, string suff) {
        string key = pref+ "-" + suff;
        if(mp.find(key) != mp.end()) return mp[key];

        vector<int> prefList = prefixTrie -> searchPrefOrSuff(pref);
        reverse(suff.begin(), suff.end());
        vector<int> suffList = suffixTrie -> searchPrefOrSuff(suff);

        int n = prefList.size(), m = suffList.size();
        int k = n-1, l = m-1;

        while(k>=0 && l>=0){
            if(prefList[k] == suffList[l]) return mp[key] = prefList[k];
            if(prefList[k] > suffList[l]) k-=1;
            else if(suffList[l] > prefList[k]) l-=1;
        }
        return mp[key] = -1;
    }
};