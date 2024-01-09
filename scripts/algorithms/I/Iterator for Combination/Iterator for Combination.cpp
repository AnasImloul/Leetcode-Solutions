// Runtime: 7 ms (Top 81.19%) | Memory: 13.10 MB (Top 50.99%)

class CombinationIterator {
public:
	vector<string>ans;
	int j=0;
	void comb(int i,string& s,int k,string& t){
		if(i==s.size()){
			if(t.size()==k) ans.push_back(t);
			return;
		}
//      Pick
		t.push_back(s[i]);
		comb(i+1,s,k,t);
		t.pop_back();
//      NotPick
		comb(i+1,s,k,t);
	}

	CombinationIterator(string characters, int combinationLength) {
		sort(characters.begin(),characters.end());
		string t="";
		comb(0,characters,combinationLength,t);
	}

	string next() {
		return ans[j++];
	}

	bool hasNext() {
		if(j==ans.size())return false;
		return true;
	}
};