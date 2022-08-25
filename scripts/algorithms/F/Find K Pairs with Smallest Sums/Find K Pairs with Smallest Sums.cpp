// Runtime: 360 ms (Top 84.93%) | Memory: 110.1 MB (Top 61.54%)
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        int m=nums1.size(),n=nums2.size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k){
                    pq.push({sum,{nums1[i],nums2[j]}});
                }else if(sum<pq.top().first){
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }else break;
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto p=pq.top().second;
            pq.pop();

            ans.push_back({p.first,p.second});
        }

        return ans;
    }
};