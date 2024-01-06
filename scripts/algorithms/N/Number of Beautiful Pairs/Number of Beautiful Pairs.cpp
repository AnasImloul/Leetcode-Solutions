// Runtime: 19 ms (Top 99.43%) | Memory: 68.20 MB (Top 21.93%)

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        vector<int> cnt(10,0);
        int res=0;
        for(int i=0;i<nums.size();i++){
            for(int n=1;n<10;n++){
                if(__gcd(nums[i]%10,n)==1){
                    res+=cnt[n];
                }
            }
            int x=nums[i],t=0;
            while(x>=10){
                // t=x%10;
                x/=10;
            }
            cnt[x]++;
        }
        return res;
    }
};
