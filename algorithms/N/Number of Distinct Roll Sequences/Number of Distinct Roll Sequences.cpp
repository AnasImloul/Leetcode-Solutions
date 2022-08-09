class Solution {
private:
	int mod = 1e9+7;

	int f(int ind,int prev1,int prev2,int n){
		//Base Case
		if(ind == n) return 1;

		int ans = 0;
		for(int i = 1;i <= 6;i++) //Exploring all possible values
			if(prev1 != i && prev2 != i && (prev1 == 0 || __gcd(prev1,i) == 1))
				ans = (ans + f(ind+1,i,prev1,n))%mod;

		return ans;
	}
public:
	int distinctSequences(int n) {
		return f(0,0,0,n);
	}
};
