class Solution {
public:
    vector<vector<int>> ans;vector<int> temp;
    void f(vector<int>& nums,int target,int i){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=nums.size())
            return;
        if(nums[i]<=target){
            temp.push_back(nums[i]);
            f(nums,target-nums[i],i+1);
            temp.pop_back();
            while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
            f(nums,target,i+1);
        }
        else
            f(nums,target,i+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        f(candidates,target,0);
        return ans;
    }
};
