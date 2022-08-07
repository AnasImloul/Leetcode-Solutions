class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            string order1 = to_string(a)+to_string(b);
            string order2 = to_string(b)+to_string(a);
            return order1>order2;
        });
        
        string ans = "";
        for(int i = 0;i<nums.size();i++){
            if(nums[0]==0) return "0";
            ans += to_string(nums[i]);
        }
        return ans;
    }
};
