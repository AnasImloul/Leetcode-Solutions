// Runtime: 205 ms (Top 89.86%) | Memory: 118.50 MB (Top 32.88%)

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        set<int> st;
        int minm = INT_MAX;
        for(int i=x;i<n;i++){
            st.insert(nums[i-x]);
            auto it = st.lower_bound(nums[i]);
            if(it!=st.end())  minm = min(minm,abs(nums[i]-*(it)));
            if(it!=st.begin()){
                --it;
                minm = min(minm,abs(nums[i]-*(it)));
            }
        }
        
        return minm;
        
    }
};
