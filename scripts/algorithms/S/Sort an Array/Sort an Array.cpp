// Runtime: 150 ms (Top 37.48%) | Memory: 50.4 MB (Top 25.68%)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto it : nums)
        {
            pq.push(it);
        }
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};