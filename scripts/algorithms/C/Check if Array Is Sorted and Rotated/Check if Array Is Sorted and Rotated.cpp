class Solution {
public:
    bool check(vector<int>& nums) {
        int n = size(nums);
        vector<int> og = nums;
        sort(og.begin(),og.end());
         for(int x = 0;x<n;x++){
             int cnt = 0;
             for(int j = 0;j<n;j++){
                 if(og[j]==nums[(j+x)%n]) cnt++;
             }
             if(cnt==n) return true;
         }
         return false;
      
    }
};