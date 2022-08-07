class Solution {
public:
	#define f first
	#define s second
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		priority_queue<pair<int,int>> pq;
		for(int i=0;i<k;i++)pq.push({nums[i],i});

		ans.push_back(pq.top().f);

		for(int i=k; i<nums.size(); i++){
			pq.push({nums[i],i});
			while(!pq.empty() && pq.top().s < i-k+1)pq.pop();
			ans.push_back(pq.top().f);
		}
		return ans;
	}
};
