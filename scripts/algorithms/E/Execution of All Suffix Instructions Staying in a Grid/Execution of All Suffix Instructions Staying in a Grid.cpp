class Solution {
public:
	vector<int> executeInstructions(int n, vector<int>& start, string s) {
		int m=s.size();
		vector<int> ans(m);
		for(int l=0;l<m;l++){
			int count=0;
			int i=start[0],j=start[1];
			for(int k=l;k<m;k++){
				if(s[k]=='L'){
					if(j-1>=0){
						j--;
						count++;
					}
					else break;
				}
				else if(s[k]=='R'){
					if(j+1<n){
						j++;
						count++;
					}
					else break;
				}
				else if(s[k]=='U'){
					if(i-1>=0){
						i--;
						count++;
					}
					else break;
				} 
				else{
					if(i+1<n){
						i++;
						count++;
					}
					else break;
				}
			}
			ans[l]=count;
		}
		return ans;
	}
};