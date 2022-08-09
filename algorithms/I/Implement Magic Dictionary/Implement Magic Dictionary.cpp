struct node{
	bool end = false;
	node *children[26];
};

class MagicDictionary {
public:

	node* root;
	void insert(string&s){
		node* cur = root;
		for(char&c : s){
			if(!cur->children[c-'a']){
				cur->children[c-'a'] = new node();
			}
			cur = cur->children[c-'a'];
		}
		cur->end=true;
	}
	MagicDictionary() {
		root = new node();
	}

	void buildDict(vector<string> dictionary) {
		for(string&s : dictionary)insert(s);
	}
	
	bool find(int i, string& s,node* cur, int mismatch){
		if(i == s.size() and mismatch==0) return cur->end;
		if(mismatch<0)return false;
		if((!cur || i == s.size()) and mismatch!=0) return false;

		int ind = s[i]-'a';
		bool ans = false;
		for(int j=0;j<26;j++){
			if(cur->children[j]){
				if(j!=ind){
					ans |= find(i+1,s,cur->children[j],mismatch-1);
				}else{
					ans |= find(i+1,s,cur->children[j],mismatch);
				}
			}
		}
		return ans;
	}
	bool search(string searchWord) {
		return find(0,searchWord,root,1);
	}
};
