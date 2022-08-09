class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
	//unordered_set is implemented using a hash table where keys are hashed into indices of a hash table
	// all operations take O(1) on average
        unordered_set<int> n1;
        unordered_set<int> n2;
        for(int i=0;i<nums1.size();i++)
            n1.insert(nums1[i]);
        
        for(int i=0;i<nums2.size();i++)
            n2.insert(nums2[i]);
        
        vector<int> ans1;
		vector<vector<int>> ans;
        for(int x:n1)
        {
            if(n2.find(x)==n2.end())
                ans1.push_back(x);
        }
		ans.push_back(ans1);
		ans1.clear();
        for(int x:n2)
        {
            if(n1.find(x)==n1.end())
                ans1.push_back(x);
        }
        ans.push_back(ans1);
        return ans;
    }
};
