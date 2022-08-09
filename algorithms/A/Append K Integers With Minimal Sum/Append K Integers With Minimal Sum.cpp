class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());
        long long s = 0;
        int i = 0;
        int prev = 0;
        while(k>0 && i<nums.size()){
            int len = nums[i] - prev - 1;
            if(len>k) len = k;
            if(len>0){
                long long int start = prev;
                long long int end = start + len;
                long long int sum = (end*(end+1))/2 - (start*(start+1))/2;
                s += sum;
                k -= len;
            }
            prev = nums[i]; i++;
        }
        if(k>0){
            long long int start = prev;
            long long int end = start + k;
            long long int sum = (end*(end+1))/2 - (start*(start+1))/2;
            s += sum;
        }
        return s;
    }
};
