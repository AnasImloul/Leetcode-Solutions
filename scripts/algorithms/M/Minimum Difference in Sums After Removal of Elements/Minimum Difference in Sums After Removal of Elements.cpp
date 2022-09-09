// Runtime: 1038 ms (Top 20.34%) | Memory: 161 MB (Top 15.01%)
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/3;
        priority_queue<int> pq;
        map<int, long long> m;
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            pq.push(nums[i]);
        }
        for(int i=0;i<=n;i++){
            if(i == 0){
                m[i] = sum;
            }
            else{
                pq.push(nums[n+i-1]);
                sum += nums[i+n-1];
                sum -= pq.top();
                pq.pop();
                m[i] = sum;
            }
        }
        sum = 0;
        priority_queue<int, vector<int>, greater<int>> p;
        for(int i=N-1;i>N-1-n;i--){
            sum += nums[i];
            p.push(nums[i]);
        }
        for(int i=0;i<=n;i++){
            if(i == 0){
                m[n-i] -= sum;
            }
            else{
                p.push(nums[N-n-i]);
                sum += nums[N-n-i];
                sum -= p.top();
                p.pop();
                m[n-i] -= sum;
            }
        }
        long long ans = 9223372036854775807;
        for(auto it : m){
            ans = min(ans, it.second);
        }
        return ans;
    }
};