class Solution {
public:
	#define f first    
	#define s second
	string longestDiverseString(int a, int b, int c) {
		priority_queue<pair<int,char>> pq;
		if(a>0)pq.push({a,'a'});        
		if(b>0)pq.push({b,'b'});        
		if(c>0)pq.push({c,'c'});

		string ans  = "";
		while(!pq.empty()){
			auto t = pq.top(); pq.pop();
			int c = t.f;
			char ch = t.s;
			if(ans.size() > 1 && ans[ans.size()-1]==ch && ch == ans[ans.size()-2]) {
				if(pq.empty())break;
				auto t = pq.top(); pq.pop();
				int c2 = t.f;
				char ch2 = t.s;
				ans += ch2;
				c2-=1;
				if(c2)pq.push({c2,ch2});
			}else{
				ans += ch;
				c-=1;
			}
			if(c)pq.push({c,ch});
		}
		return ans;
	}
};
