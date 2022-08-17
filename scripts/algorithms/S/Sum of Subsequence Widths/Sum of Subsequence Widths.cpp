class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        vector < long long > pow(nums.size() ); 
        pow[0] = 1;
          for(int i = 1 ; i<nums.size(); i++){ 
             pow[i] = pow[i-1] * 2 % 1000000007; 
          }
        sort(nums.begin() , nums.end()); 
       long long ans = 0 ;   
        for(int i = 0 ; i<nums.size(); i++){ 
              ans = (ans + pow[i]*nums[i]) % 1000000007; 
               ans = (ans - pow[nums.size()-i-1] * (long long)nums[i] ) % 1000000007; 
           
          } 
        return ans; 
    }
};
