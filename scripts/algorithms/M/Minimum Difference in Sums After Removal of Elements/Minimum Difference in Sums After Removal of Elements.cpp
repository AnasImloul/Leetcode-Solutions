// Runtime: 248 ms (Top 89.8%) | Memory: 136.40 MB (Top 85.71%)

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        long long ans = LLONG_MAX, suml = 0, sumr = 0, sumll, sumrr;
        int n = nums.size()/3;
        priority_queue<int> lpq;
        priority_queue<int,vector<int>,greater<int>> rpq;
        for(int i=0;i<n;i++) {
            lpq.push(nums[i]), suml += nums[i];
            rpq.push(nums[i+2*n]), sumr += nums[i+2*n];
        }
        sumll = suml;
        sumrr = sumr;
        vector<long long> leftdp(n), rightdp(n);
        ans = min(ans,suml-sumr);
        for(int i=n;i<2*n;i++){
            if(lpq.top()>nums[i]){
                suml -= lpq.top();
                suml += nums[i];
                lpq.pop();
                lpq.push(nums[i]);
            }
            leftdp[i-n] = suml;
        }
        for(int i=2*n-1;i>=n;i--){
            if(rpq.top()<nums[i]){
                sumr -= rpq.top();
                sumr += nums[i];
                rpq.pop();
                rpq.push(nums[i]);
            }
            rightdp[i-n] = sumr;
        }
        for(int i=0;i+1<n;i++) ans = min(ans,leftdp[i]-rightdp[i+1]);
        ans = min(ans,leftdp[n-1]-sumrr);
        ans = min(ans,sumll-rightdp[0]);
        return ans;
    }
};
