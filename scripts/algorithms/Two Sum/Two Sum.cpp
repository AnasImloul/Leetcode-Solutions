class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        vector<int>v;
		/*Push every element along with its index in the HashMap.*/
        for(int i=0;i<nums.size();i++)
        {
            m.insert({nums[i],i});
        }
		/*To get the answer/result, we need to search for "target-nums[i]".*/
        for(int i=0;i<nums.size();i++)
        {
            if(m.count(target-nums[i])<=0)
                continue;
				/*If the key doesn't exist in the Hashmap, continue the loop.*/
            else if(i==m[target-nums[i]])
                continue;
				/*If the same index is repeated in the answer then to avoid such condition we have to apply the above condition. For Example - nums={3,2,4}, target=6, if the above condition is not applied then the result will become [0,0] which would be wrong.*/
            else{
                v.push_back(i);
                v.push_back(m[target-nums[i]]);
                break;
            }
			// This push_backs the answer.
        }
        return v;
    }
};
