class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        long long n = tiles.size() , ans = INT_MIN;
        sort(tiles.begin(),tiles.end());
        vector<long long> len(n) , li(n);
		//len array stores the prefix sum of tiles
		//li array stores the last index tiles[i]
        for(int i=0;i<n;i++){
            len[i] = (long long)(tiles[i][1] - tiles[i][0] + 1);
            len[i]+=(i==0) ? 0 : len[i-1];
            li[i] = tiles[i][1];
        }
        
        for(int i=0 ; i<n ; i++){
		   //sp means starting tile index
		   //ep means ending tile index
            long long sp = tiles[i][0] , ep = tiles[i][0] + (long long)carpetLen-1 , tc=0;
            int idx = lower_bound(li.begin(),li.end(),ep) - li.begin();
			
			//logic to take count of tiles covered
            if(idx==n){
                tc = len[n-1];
                tc-=(i==0) ? 0 : len[i-1];
            }else{
                tc = ep<tiles[idx][0] ? 0 : ep - (long long)tiles[idx][0]  + 1;
                idx--;
                if(idx>=0){
                    tc+=len[idx];
                    tc-=(i==0) ? 0 : len[i-1];
                }
            }
            ans = max(ans,tc);
        }
        return (int)ans;
    }
};
