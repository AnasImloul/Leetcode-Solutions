class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int>st;
        int n=heights.size();
		
		// Yes my friend, we can use vector just like stack
        vector<int>ans(n,0);
        st.push_back(heights[n-1]);
        for(int i=n-2;i>=0;i--)
        {
        
            std::vector<int>::iterator up;
            up = std::upper_bound(st.begin(), st.end(), heights[i], std::greater<int>());
            
            int ele = up-st.begin();
           
		   // This is just consequence of appling binary search in decreasing array
		   if(ele!=0)
                ele--;
            ele = st.size()-ele;
            
            ans[i]=ele;
			// Update Mono Stack 
            while(st.size()>0&&st.back()<=heights[i])
                st.pop_back();
            st.push_back(heights[i]);
        }
        return ans;
    }
};
