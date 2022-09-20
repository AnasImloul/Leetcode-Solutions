// Runtime: 2423 ms (Top 5.03%) | Memory: 47.6 MB (Top 92.56%)
class Solution {
private:
    int mod=1e9+7;
    int multiply(int a,int b){
        if(b==0){
            return 0;
        } else if(b%2==0){
            int ans=multiply(a,b/2);
            return (ans%mod+ans%mod)%mod;
        } else {
            int ans=multiply(a,b-1);
            return (a%mod+ans%mod)%mod;
        }
    }
    int power(int b,int e){
        if(e==0){
            return 1;
        } else if(e%2==0){
            int ans=power(b,e/2);
            return multiply(ans,ans);
        } else {
            int ans=power(b,e-1);
            return multiply(b,ans);
        }
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int start=0,end=0;
        while(end<nums.size() and nums[start]+nums[end]<=target){
            end++;
        }
        end--;
        int ans=0;
        while(start<=end){
            if(nums[start]+nums[end]<=target){
                ans=(ans%mod+power(2,end-start))%mod;
                start++;
            } else {
                end--;
            }
        }
        return ans;
    }
};