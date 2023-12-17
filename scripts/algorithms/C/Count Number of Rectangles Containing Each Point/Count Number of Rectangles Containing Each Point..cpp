// Runtime: 719 ms (Top 16.47%) | Memory: 91.40 MB (Top 39.2%)

class Solution {
public:
    
	// helper fxn for binary search
    int binsear(vector<int>& arr, int x){
        int l=0, r=arr.size()-1;
        
        int anstillnow=arr.size(); 
		// if we find no m such that arr[m]>=x, means that our x is greater than all values of length, in such case we return idx n (i.e. size of arr)
		// reason being, we substract our idx by size of arr to get number of rectangles greater than that in main fxn, so return arr.size would give us 0 (which we want)
		
        while(l<=r){
            int m= l + (r-l)/2;
            
            
            if(arr[m]>=x){
                anstillnow=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
            
        }
        
        return anstillnow;
    }
    
    
    vector<int> countRectangles(vector<vector<int>>& rect, vector<vector<int>>& points) {
        
        unordered_map<int, vector<int>> htl;
        // maps heights to all the lengths of rectangles with that height
        
        for(int i=0; i<rect.size(); i++){       
            htl[rect[i][1]].push_back(rect[i][0]);
        }
        
		// have to sort the containers to apply binary search
        for(int i=0; i<=100; i++){
            sort(htl[i].begin(), htl[i].end());
        }
        
		
        vector<int> ans;
		
        for(vector<int> p: points){
            int x=p[0], y=p[1];
            int ct=0;
            for(int j= y; j<=100; j++){
                if(htl.find(j)!=htl.end()){
                    ct+= htl[j].size()- binsear(htl[j], x);
					// binary search return the idx in array from which the values are >= x
					// the values at this and right of this are the lengths possible
					// so substract by size of array to get the number
                }
            }
            
            ans.push_back(ct);
            
        }
        
        return ans;
    }
};
