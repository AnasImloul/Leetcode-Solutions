// Runtime: 373 ms (Top 42.29%) | Memory: 91.1 MB (Top 60.46%)
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        nums.push_back(0);
        stack<int> st ;
        int n = nums.size(), res = 0;
        for(int i=0; i<n ; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                int height = nums[st.top()];
                st.pop();
                int left = st.empty() ? -1: st.top();
                if(k < i && k > left) res = max(height* (i-left-1), res);
            }
            st.push(i);
        }
        return res;
    }
};