class StreamChecker {
    struct Trie {
        Trie* suffixLink; //this is where it will fallback to when a letter can't be matched
        int id = -1; //this id will be 0 or greater if it matches a word
        map<char, Trie*> next;
    };
public:
    Trie* root;
    Trie* queryPtr;
    int uniqueIds = 0; //used to count all the unique words discovered and as part of the Trie id system
    
    StreamChecker(vector<string>& words) {
        root = new Trie();
        
		//standard trie traversal but keeping track of new words via id system
        for (string& word: words) {
            Trie* p = root;
            for (char c: word) {
                if (p->next.find(c) == p->next.end()) {
                    p->next.insert({ c, new Trie() });
                }
                p = p->next.at(c);
            }
            if (p->id == -1) {
                p->id = uniqueIds++;
            }
        }
        
        queue<Trie*> q;
        for (pair<char, Trie*> itr: root->next) {
            q.push(itr.second);
            itr.second->suffixLink = root;
        }
        
		//BFS traversal to build the automaton
        while (q.size()) {
            Trie* curr = q.front();
            q.pop();
            for (pair<char, Trie*> e: curr->next) {
                char c = e.first;
                Trie* node = e.second;
				
                Trie* ptr = curr->suffixLink;
                while (ptr != root && ptr->next.find(c) == ptr->next.end()) {
                    ptr = ptr->suffixLink;
                }
				//find the next suffixLink if it matches the current character or fallback to the root
                node->suffixLink = ptr->next.find(c) != ptr->next.end() ? ptr->next.at(c) : root;
				
				//if the current suffixLink happens to also be a word we should store its id to make it quick to find
                if (node->suffixLink->id != -1) {
                    node->id = node->suffixLink->id;
                }
                q.push(node);
            }
        }
		//the query ptr will now track every new streamed character and can be used to quickly find words
        queryPtr = root;
    }
    
    bool query(char letter) {
		//if the next letter can't be found and we're not at the root, we'll trace back until we find the longest suffix that matches
        while (queryPtr != root && queryPtr->next.find(letter) == queryPtr->next.end()) {
            queryPtr = queryPtr->suffixLink;
        }
        queryPtr = queryPtr->next.find(letter) != queryPtr->next.end() ? queryPtr->next.at(letter) : root;
		//if any word is found it will have an id that isn't -1
        return queryPtr->id != -1;
    }
};
