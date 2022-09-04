// Runtime: 12 ms (Top 97.44%) | Memory: 13.7 MB (Top 73.00%)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> up;
        priority_queue<pair<int,int>> pq;
        vector<int> a;
        for(int i=0;i<nums.size();i++){
            up[nums[i]]++;
        }
        for(auto& i:up){
            pq.push({i.second,i.first});
        }

        while(k--){
            a.push_back(pq.top().second);
                pq.pop();
        }
        return a;
    }
};