// Runtime: 373 ms (Top 14.90%) | Memory: 88.8 MB (Top 51.45%)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> result(n, 0);
        for(int i = 0; i<n; i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                result[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};