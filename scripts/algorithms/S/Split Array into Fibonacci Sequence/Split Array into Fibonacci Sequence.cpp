// Runtime: 0 ms (Top 100.0%) | Memory: 7.80 MB (Top 37.58%)

class Solution {
public:
	vector<int> ans;

	bool getFibo(string &s,int i,long a,long b,int n) {
		if(i==s.length()) return n>2;

		long num=0;
		for(int x=i;x<s.length();x++) {
			num= num*10+s[x]-'0';
			if(num>INT_MAX) break;

			bool chk=false;    
			ans.push_back(num);
			if(n<2) chk=getFibo(s,x+1,b,num,n+1);
			else if(a+b==num) chk= getFibo(s,x+1,b,num,n+1);
			if(chk) return true;
			ans.pop_back();

			if(num==0) break;
		}
		return false;
	}

	vector<int> splitIntoFibonacci(string S) {
		ans.clear();
		getFibo(S,0,0,0,0);
		return ans;
	}
};