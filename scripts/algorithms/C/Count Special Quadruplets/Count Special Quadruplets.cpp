class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        int ans=0;
        for(int i=1;i<n-2;i++){
            for(int j=0;j<i;j++){
                m[nums[i]+nums[j]]++;
            }
            for(int k=i+2;k<n;k++){
               ans+= m[nums[k]-nums[i+1]];
            }
        }
        return ans;
    }
};