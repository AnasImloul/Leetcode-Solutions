class Solution {
	public:
	long long int dp[11][2][2][(1<<10)];
	int f(int idx,bool flag,bool repeat,int mask,string &s){

		if(idx==s.size()){
			return repeat;
		}

		if(dp[idx][flag][repeat][mask]!=-1) return dp[idx][flag][repeat][mask];

		int limit = s[idx]-'0';
		if(flag) limit = 9;

		int ans=0;

		for(int digit=0;digit<=limit;digit++){



			 if(digit < (s[idx]-'0')){

					if(digit==0 and mask==0){
						 ans+=f(idx+1,true,false,mask,s);
					}

					else if(mask&(1<<digit)){
						ans+=f(idx+1,true,true,mask,s);
					}
					else{
						ans+=f(idx+1,true,repeat,mask | (1<<digit),s);
					}


			}
			else{
				if(digit==0 and mask==0){
					ans+=f(idx+1,flag,false,mask,s);
				}

					else if(mask&(1<<digit)){
						ans+=f(idx+1,flag,true,mask,s);
					}
					else{
						ans+=f(idx+1,flag,repeat,mask | (1<<digit),s);
					}

			}

		}

		return dp[idx][flag][repeat][mask]=ans;
	}
	int numDupDigitsAtMostN(int n) {

		string r = to_string(n);
		memset(dp,-1,sizeof dp);



		return f(0,false,false,0,r);
	}
