class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		int cnt=0,n=row.size();
		// first of all making row element equal  ex for [0,1],[2,3] --> [0,0] ,[2,2]
		for(auto &x : row){
			if(x&1){
				x--;
			}
		}

		for( int i=0; i<n; i+=2){
			int ele=row[i];
			int j=i+1;
			// for every num find location of equal one,
			while(j<n and row[j]!=ele) j++;
			if(j!=i+1){
						// not in same couch then cnt++ , and swap
				swap(row[j], row[i+1]);
				cnt++;
			}
		}
		return cnt;
	}
};
