// Runtime: 39 ms (Top 34.86%) | Memory: 18.3 MB (Top 20.63%)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        priority_queue<int> pq;
        for(auto &i : nums)
            pq.push(i);

        for(int i = 1; i < nums.size(); i += 2)
            nums[i] = pq.top(), pq.pop();

        for(int i = 0; i < nums.size(); i += 2)
            nums[i] = pq.top(), pq.pop();
    }
};