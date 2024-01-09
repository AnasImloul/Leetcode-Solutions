// Runtime: 14 ms (Top 88.14%) | Memory: 13.50 MB (Top 98.31%)

class Solution {
public:
	vector<int> numMovesStonesII(vector<int>& stones) {
		sort(stones.begin(),stones.end());
		int n=stones.size();
		int MAX=0;
		int MIN=INT_MAX;
		int a=stones.back()-stones[1]+1-(n-1);
		int b=stones[n-2]-stones[0]+1-(n-1);
		int j=0;
		MAX=max(a,b);
		for(int i=0;i<n;i++){
			while(j<n && stones[j]-stones[i]+1<n){
				j++;
			}
			if(j>=n){
				break;
			}
			int gap;
			if(stones[j]-stones[i]+1==n){
				gap=n-(j-i+1);
			}
			else if(j-1-i+1==n-1){
				gap=2;
			}
			else{
				gap=n-(j-1-i+1);
			}
			MIN=min(MIN,gap);
		}
		return {MIN,MAX};
	}
};